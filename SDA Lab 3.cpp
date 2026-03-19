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

    cout << "Введите: название режиссер год жанр время\n";
    cin >> f.name >> f.rej >> f.year >> f.janr >> f.time;

    return f;
}

void printFilms(film* arr, int size) {

    if (size == 0) {
        cout << "Массив пуст\n";
        return;
    }

    for (int i = 0; i < size; i++) {

        cout << "\nФильм " << i << ":\n";

        cout << "Название: " << arr[i].name << endl;
        cout << "Режиссер: " << arr[i].rej << endl;
        cout << "Год: " << arr[i].year << endl;
        cout << "Жанр: " << arr[i].janr << endl;
        cout << "Время: " << arr[i].time << endl;
    }
}

void expandArray(film*& arr, int& capacity, int size, int addCount) {

    if (addCount <= 0) return;

    int newCapacity = capacity + addCount;

    film* newArr = new film[newCapacity];

    for (int i = 0; i < size && i < newCapacity; i++) {
        newArr[i] = arr[i];
    }

    delete[] arr;

    arr = newArr;
    capacity = newCapacity;

    cout << "Массив расширен. Новая вместимость: " << capacity << endl;
}

void pushBack(film*& arr, int& size, int& capacity) {

    if (size >= capacity) {
        expandArray(arr, capacity, size, 1);
    }

    arr[size] = inputFilm();
    size++;
}

void popBack(int& size) {

    if (size > 0) {
        size--;
        cout << "Последний элемент удален\n";
    }
    else {
        cout << "Массив пуст\n";
    }
}

void deleteByIndex(film* arr, int& size) {
    if (size == 0) {
        cout << "Массив пуст\n";
        return;
    }

    int num;
    cout << "Введите номер фильма для удаления (1-" << size << "): ";
    cin >> num;

    int index = num - 1;
    if (index < 0 || index >= size) {
        cout << "Неверный номер\n";
        return;
    }

    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;
    cout << "Фильм удален\n";
}

void editFilmField(film* arr, int index, int size) {

    if (index < 0 || index >= size) {
        cout << "Неверный индекс\n";
        return;
    }

    int choice;

    cout << "Что изменить?\n";
    cout << "1 - название\n";
    cout << "2 - режиссер\n";
    cout << "3 - год\n";
    cout << "4 - жанр\n";
    cout << "5 - время\n";

    cin >> choice;

    switch (choice) {

    case 1:
        cout << "Новое название: ";
        cin >> arr[index].name;
        break;

    case 2:
        cout << "Новый режиссер: ";
        cin >> arr[index].rej;
        break;

    case 3:
        cout << "Новый год: ";
        cin >> arr[index].year;
        break;

    case 4:
        cout << "Новый жанр: ";
        cin >> arr[index].janr;
        break;

    case 5:
        cout << "Новое время: ";
        cin >> arr[index].time;
        break;

    default:
        cout << "Неверный выбор\n";
    }
}

void searchByField(film* arr, int size) {

    if (size == 0) {
        cout << "Массив пуст\n";
        return;
    }

    int field;

    cout << "По какому полю искать?\n";
    cout << "1 - название\n";
    cout << "2 - режиссер\n";
    cout << "3 - год\n";
    cout << "4 - жанр\n";
    cout << "5 - время\n";

    cin >> field;

    bool found = false;

    if (field == 5) {

        double value;

        cout << "Введите время: ";
        cin >> value;

        for (int i = 0; i < size; i++) {

            if (arr[i].time == value) {

                cout << "\nНайден фильм (индекс " << i << "):\n";

                cout << arr[i].name << endl;
                cout << arr[i].rej << endl;
                cout << arr[i].year << endl;
                cout << arr[i].janr << endl;
                cout << arr[i].time << endl;

                found = true;
            }
        }
    }
    else {

        string value;

        cout << "Введите значение: ";
        cin >> value;

        for (int i = 0; i < size; i++) {

            bool match = false;

            if (field == 1 && arr[i].name == value) match = true;
            if (field == 2 && arr[i].rej == value) match = true;
            if (field == 3 && arr[i].year == value) match = true;
            if (field == 4 && arr[i].janr == value) match = true;

            if (match) {

                cout << "\nНайден фильм (индекс " << i << "):\n";

                cout << arr[i].name << endl;
                cout << arr[i].rej << endl;
                cout << arr[i].year << endl;
                cout << arr[i].janr << endl;
                cout << arr[i].time << endl;

                found = true;
            }
        }
    }

    if (!found) {
        cout << "Совпадений не найдено\n";
    }
}

void clearArray(film*& arr, int& size, int& capacity) {

    delete[] arr;

    arr = nullptr;

    size = 0;
    capacity = 0;

    cout << "Память полностью освобождена\n";
}

void insertAt(film*& arr, int& size, int& capacity, int index) {
    if (index < 0 || index > size) {
        cout << "Неверный индекс\n";
        return;
    }

    if (size >= capacity) {
        expandArray(arr, capacity, size, 1);
    }

    for (int i = size; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    arr[index] = inputFilm();
    size++;

    cout << "Фильм вставлен на позицию " << index << endl;
}


void sortFilms(film* arr, int size) {
    if (size <= 1) return;

    int field;
    cout << "Сортировать по полю:\n";
    cout << "1 - название\n";
    cout << "2 - режиссер\n";
    cout << "3 - год\n";
    cout << "4 - жанр\n";
    cout << "5 - время\n";
    cin >> field;

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            bool swapNeeded = false;

            switch (field) {
            case 1:
                if (arr[j].name > arr[j + 1].name) swapNeeded = true;
                break;
            case 2:
                if (arr[j].rej > arr[j + 1].rej) swapNeeded = true;
                break;
            case 3:
                if (arr[j].year > arr[j + 1].year) swapNeeded = true;
                break;
            case 4:
                if (arr[j].janr > arr[j + 1].janr) swapNeeded = true;
                break;
            case 5:
                if (arr[j].time > arr[j + 1].time) swapNeeded = true;
                break;
            default:
                cout << "Неверный выбор\n";
                return;
            }

            if (swapNeeded) {
                film temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Массив отсортирован\n";
}


int main() {

    setlocale(LC_ALL, "RU");

    int capacity = 2;
    int size = 0;

    film* arr = new film[capacity];

    int choice;

    do {

        cout << "\nМЕНЮ:\n";
        cout << "1 - Добавить фильмы\n";
        cout << "2 - Удалить последний фильм\n";
        cout << "3 - Показать фильмы\n";
        cout << "4 - Поиск фильма\n";
        cout << "5 - Редактировать фильм\n";
        cout << "6 - Расширить массив\n";
        cout << "7 - Очистить массив\n";
        cout << "8 - Удалить фильм по номеру\n";
        cout << "9 - Вставить фильм на указанную позицию\n";
        cout << "10 - Сортировать массив\n";
        cout << "0 - Выход\n";

        cin >> choice;

        switch (choice) {

        case 1: {

            int count;

            cout << "Сколько фильмов добавить: ";
            cin >> count;

            for (int i = 0; i < count; i++) {
                pushBack(arr, size, capacity);
            }

            break;
        }

        case 2:
            popBack(size);
            break;

        case 3:
            printFilms(arr, size);
            break;

        case 4:
            searchByField(arr, size);
            break;

        case 5: {

            int index;

            cout << "Введите индекс фильма: ";
            cin >> index;

            editFilmField(arr, index, size);

            break;
        }

        case 6: {

            int add;

            cout << "На сколько элементов расширить массив: ";
            cin >> add;

            expandArray(arr, capacity, size, add);

            break;
        }

        case 7:

            clearArray(arr, size, capacity);

            capacity = 2;
            size = 0;
            arr = new film[capacity];

            break;

        case 8:
            deleteByIndex(arr, size);
            break;

        case 9: {
            int index;
            cout << "Введите позицию для вставки (0-" << size << "): ";
            cin >> index;
            insertAt(arr, size, capacity, index);
            break;
        }

        case 10:
            sortFilms(arr, size);
            break;

        case 0:

            clearArray(arr, size, capacity);

            break;

        default:
            cout << "Неверный выбор\n";
        }

    } while (choice != 0);

    return 0;
}