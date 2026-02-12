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

void parameters(film a[], int n) {
    for (int i = 0; i <= n - 1; i++) {
        cout << "Введите данные " << i << " фильма: \nимя, режисёр, год, жанр, время\n";
        cin >> a[i].name;
        cin >> a[i].rej;
        cin >> a[i].year;
        cin >> a[i].janr;
        cin >> a[i].time;
    }
}

void log(film a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Данные " << i << " структуры" << endl;
        cout << a[i].name << endl << a[i].rej << endl << a[i].year << endl << a[i].janr << endl << a[i].time << endl;
    }
}

void editFilmField(film arr[], int index, int n) {
    if (index < 0 || index >= n){
        cout << "Неверный индекс!\n";
        return;
    }

    int choice;
    cout << "Редактируем элемент с индексом " << index << ":\n";
    cout << "1. имя, режисёр, год, жанр, время\nВыберите поле для редактирования: ";
    cin >> choice;
    cin.ignore();

    switch (choice) {
    case 1:
        cout << "Введите новое имя: ";
        cin >> arr[index].name;
        break;
    case 2:
        cout << "Введите нового режисера: ";
        cin >> arr[index].rej;
        break;
    case 3:
        cout << "Введите новый год: ";
        cin >> arr[index].year;
        break;
    case 4:
        cout << "Введите новое имя: ";
        cin >> arr[index].janr;
        break;
    case 5:
        cout << "Введите нового режисера: ";
        cin >> arr[index].time;
        break;
    default:
        cout << "Неверный выбор!\n";
        break;
    }
}


int search(film a[], int size, const string& keyName) {
    for (int i = 0; i < size; i++) {
        if (a[i].name == keyName) {
            return i + 1;
        }
    }
    return -1;
}


int main()
{
    setlocale(LC_ALL, "RU");
    int quit = 1;
    while (quit == 1)
    {
        int choice;
        int index;
        int choicee;
        string name;
        int indexx;
        film a[2];
        parameters(a, sizeof(a) / sizeof(a[0]));
        log(a, sizeof(a) / sizeof(a[0]));
        cout << "Хотите изменить поле объекта структуры? Напишите 1 если да, 0 если нет: " << endl;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Введите номер объекта структуры (фильма): " << endl;
            cin >> index;
            editFilmField(a, index, sizeof(a) / sizeof(a[0]));
        }
        cout << "Хотите найти объект по ключевому полю name? Напишите 1 если да, 0 если нет: " << endl;
        cin >> choicee;

        if (choicee == 1) {
            cout << "Введите имя фильма: " << endl;
            cin >> name;
            int nomer_objecta = search(a, sizeof(a) / sizeof(a[0]), name);
            if (nomer_objecta == -1) {
                cout << "неверный name";
            }
            else {
                cout << "Объект по имени введенного name является " << nomer_objecta << "по счёту(не массива(+1))";
            }
        }



        cout << "завершить программу? Напишите 0 если да, 1 если нет:" << endl;
        cin >> quit;

    }
    return 1;
}
