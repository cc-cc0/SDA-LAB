#include "data.hpp"
#include <iostream>
#include <locale>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    int capacity = 2;
    int size = 0;
    film* arr = new film[capacity];

    
    loadFromFile("films.txt", arr, size, capacity);

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
            
            saveToFile("films.txt", arr, size);
            clearArray(arr, size, capacity);
            break;
        default:
            cout << "Неверный выбор\n";
        }
    } while (choice != 0);

    return 0;
}