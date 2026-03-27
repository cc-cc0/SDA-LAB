#ifndef DATA_HPP
#define DATA_HPP

#include <string>

struct film {
    std::string name;
    std::string rej;
    std::string year;
    std::string janr;
    double time = 0;
};


film inputFilm();
void printFilms(const film* arr, int size);


void expandArray(film*& arr, int& capacity, int size, int addCount);
void pushBack(film*& arr, int& size, int& capacity);
void popBack(int& size);
void deleteByIndex(film* arr, int& size);
void insertAt(film*& arr, int& size, int& capacity, int index);
void clearArray(film*& arr, int& size, int& capacity);


void editFilmField(film* arr, int index, int size);
void searchByField(const film* arr, int size);
void sortFilms(film* arr, int size);


void saveToFile(const char* filename, const film* arr, int size);
void loadFromFile(const char* filename, film*& arr, int& size, int& capacity);

#endif