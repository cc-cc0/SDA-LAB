#include <iostream>
#include <locale>
using namespace std;

struct film {
    string name;
    string rej;
    string year;
    string janr;
    double time = 0;
};


film inputFilm() {
    film f;
    cout << "Введите: имя режиссёр год жанр время\n";
    cin >> f.name >> f.rej >> f.year >> f.janr >> f.time;
    return f;
}


void printFilms(film* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << "\nФильм " << i << ":\n";
        cout << arr[i].name << endl;
        cout << arr[i].rej << endl;
        cout << arr[i].year << endl;
        cout << arr[i].janr << endl;
        cout << arr[i].time << endl;
    }
}


void expandArray(film*& arr, int& capacity, int size, int addCount) {
    if (addCount <= 0) return;

    int newCapacity = capacity + addCount;
    film* newArr = new film[newCapacity];

    int copyCount = (size < newCapacity) ? size : newCapacity;

    for (int i = 0; i < copyCount; i++) {
        newArr[i] = arr[i];
    }

    delete[] arr;
    arr = newArr;
    capacity = newCapacity;
}
 

void pushBack(film*& arr, int& size, int& capacity) {
    if (size >= capacity) {
        expandArray(arr, capacity, size, 2);
    }

    arr[size] = inputFilm();
    size++;
}


void popBack(int& size) {
    if (size > 0) {
        size--;
        cout << "Последний элемент удалён\n";
    }
    else {
        cout << "Массив пуст\n";
    }
}


int searchByName(film* arr, int size, const string& name) {
    for (int i = 0; i < size; i++) {
        if (arr[i].name == name)
            return i;
    }
    return -1;
}


void clearArray(film*& arr, int& size, int& capacity) {
    delete[] arr;
    arr = nullptr;
    size = 0;
    capacity = 0;
    cout << "Память полностью освобождена\n";
}

int main() {
    setlocale(LC_ALL, "RU");

    int capacity = 2;
    int size = 0;
    film* arr = new film[capacity];

    int choice;
    do {
        cout << "\n1 - Добавить фильм\n";
        cout << "2 - Удалить последний\n";
        cout << "3 - Показать все\n";
        cout << "4 - Поиск по имени\n";
        cout << "0 - Выход\n";
        cin >> choice;

        switch (choice) {
        case 1:
            pushBack(arr, size, capacity);
            break;
        case 2:
            popBack(size);
            break;
        case 3:
            printFilms(arr, size);
            break;
        case 4: {
            string name;
            cout << "Введите имя: ";
            cin >> name;
            int idx = searchByName(arr, size, name);
            if (idx == -1)
                cout << "Фильм не найден\n";
            else
                cout << "Найден с индексом: " << idx << endl;
            break;
        }
        case 0:
            clearArray(arr, size, capacity);
            break;
        default:
            cout << "Неверный выбор\n";
        }
    } while (choice != 0);

    return 0;
}