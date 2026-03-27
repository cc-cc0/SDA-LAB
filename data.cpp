#include "data.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


film inputFilm() {
    film f;
    cout << "Enter: title director year genre time\n";
    cin >> f.name >> f.rej >> f.year >> f.janr >> f.time;
    return f;
}

void printFilms(const film* arr, int size) {
    if (size == 0) {
        cout << "Array is empty\n";
        return;
    }
    for (int i = 0; i < size; i++) {
        cout << "\nFilm " << i << ":\n";
        cout << "Title: " << arr[i].name << endl;
        cout << "Director: " << arr[i].rej << endl;
        cout << "Year: " << arr[i].year << endl;
        cout << "Genre: " << arr[i].janr << endl;
        cout << "Duration: " << arr[i].time << endl;
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
    cout << "Array expanded. New capacity: " << capacity << endl;
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
        cout << "Last film removed\n";
    }
    else {
        cout << "Array is empty\n";
    }
}

void deleteByIndex(film* arr, int& size) {
    if (size == 0) {
        cout << "Array is empty\n";
        return;
    }
    int num;
    cout << "Enter film number to delete (1-" << size << "): ";
    cin >> num;
    int index = num - 1;
    if (index < 0 || index >= size) {
        cout << "Invalid number\n";
        return;
    }
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    cout << "Film deleted\n";
}

void insertAt(film*& arr, int& size, int& capacity, int index) {
    if (index < 0 || index > size) {
        cout << "Invalid index\n";
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
    cout << "Film inserted at position " << index << endl;
}

void clearArray(film*& arr, int& size, int& capacity) {
    delete[] arr;
    arr = nullptr;
    size = 0;
    capacity = 0;
    cout << "Memory completely freed\n";
}


void editFilmField(film* arr, int index, int size) {
    if (index < 0 || index >= size) {
        cout << "Invalid index\n";
        return;
    }
    int choice;
    cout << "What to change?\n";
    cout << "1 - title\n";
    cout << "2 - director\n";
    cout << "3 - year\n";
    cout << "4 - genre\n";
    cout << "5 - duration\n";
    cin >> choice;
    switch (choice) {
    case 1:
        cout << "New title: ";
        cin >> arr[index].name;
        break;
    case 2:
        cout << "New director: ";
        cin >> arr[index].rej;
        break;
    case 3:
        cout << "New year: ";
        cin >> arr[index].year;
        break;
    case 4:
        cout << "New genre: ";
        cin >> arr[index].janr;
        break;
    case 5:
        cout << "New duration: ";
        cin >> arr[index].time;
        break;
    default:
        cout << "Invalid choice\n";
    }
}

void searchByField(const film* arr, int size) {
    if (size == 0) {
        cout << "Array is empty\n";
        return;
    }
    int field;
    cout << "Search by field:\n";
    cout << "1 - title\n";
    cout << "2 - director\n";
    cout << "3 - year\n";
    cout << "4 - genre\n";
    cout << "5 - duration\n";
    cin >> field;
    bool found = false;
    if (field == 5) {
        double value;
        cout << "Enter duration: ";
        cin >> value;
        for (int i = 0; i < size; i++) {
            if (arr[i].time == value) {
                cout << "\nFilm found (index " << i << "):\n";
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
        cout << "Enter value: ";
        cin >> value;
        for (int i = 0; i < size; i++) {
            bool match = false;
            if (field == 1 && arr[i].name == value) match = true;
            if (field == 2 && arr[i].rej == value) match = true;
            if (field == 3 && arr[i].year == value) match = true;
            if (field == 4 && arr[i].janr == value) match = true;
            if (match) {
                cout << "\nFilm found (index " << i << "):\n";
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
        cout << "No matches found\n";
    }
}

void sortFilms(film* arr, int size) {
    if (size <= 1) return;
    int field;
    cout << "Sort by field:\n";
    cout << "1 - title\n";
    cout << "2 - director\n";
    cout << "3 - year\n";
    cout << "4 - genre\n";
    cout << "5 - duration\n";
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
                cout << "Invalid choice\n";
                return;
            }
            if (swapNeeded) {
                film temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout << "Array sorted\n";
}


void saveToFile(const char* filename, const film* arr, int size) {
    ofstream out(filename);
    if (!out) {
        cerr << "Error: Could not open file for writing\n";
        return;
    }
    out << size << '\n';
    for (int i = 0; i < size; ++i) {
        out << arr[i].name << ' '
            << arr[i].rej << ' '
            << arr[i].year << ' '
            << arr[i].janr << ' '
            << arr[i].time << '\n';
    }
    out.close();
    cout << "Data saved to " << filename << "\n";
}

void loadFromFile(const char* filename, film*& arr, int& size, int& capacity) {
    ifstream in(filename);
    if (!in) {
        
        return;
    }
    int newSize;
    in >> newSize;
    if (newSize <= 0) {
        in.close();
        return;
    }
    film* newArr = new film[newSize];
    int idx = 0;
    string name, rej, year, janr;
    double time;
    while (idx < newSize && in >> name >> rej >> year >> janr >> time) {
        newArr[idx].name = name;
        newArr[idx].rej = rej;
        newArr[idx].year = year;
        newArr[idx].janr = janr;
        newArr[idx].time = time;
        ++idx;
    }
    in.close();
    if (idx != newSize) {
        cerr << "Warning: Inconsistent file data. Loaded " << idx
            << " films instead of " << newSize << "\n";
        newSize = idx;
    }
    delete[] arr;
    arr = newArr;
    size = newSize;
    capacity = newSize;
    cout << "Loaded " << size << " films from " << filename << "\n";
}