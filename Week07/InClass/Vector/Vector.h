//
// Created by Mateev, Nikolay on 4/12/17.
//

#ifndef WEEK07_VECTOR_H
#define WEEK07_VECTOR_H
#include <iostream>
#include <climits>
#include <cassert>
using namespace std;


class Vector {
private:
    int* container;
    int size;
    int capacity;

    void copy(const Vector& other);
    void destroy();

    void resize(int newCapacity);
    void removeAt(int index);
    void swap(int& lhs, int& rhs);
public:
    Vector();
    Vector(const int* arr, int size);
    Vector(const Vector& other);
    Vector& operator=(const Vector& other);
    ~Vector();

    int getSize() const;
    int getCapacity() const;

    bool isEmpty() const;

    void sort(bool increasing);
    bool isSorted(bool increasing) const;

    int getAt(int index);
    void setAt(int index, int element);

    void add(int element);
    void remove(int element);

    Vector& operator+=(const Vector& other);
    Vector& operator-=(const Vector& other);
    Vector& operator*=(const Vector& other);
    Vector& operator/=(const Vector& other);

    friend Vector operator+(const Vector& v1, const Vector& v2);
    friend Vector operator-(const Vector& v1, const Vector& v2);
    friend Vector operator*(const Vector& v1, const Vector& v2);
    friend Vector operator/(const Vector& v1, const Vector& v2);

    const int operator[](int index) const;
    int& operator[](int index);

    friend ostream& operator<<(ostream& os, const Vector& obj);
    friend istream& operator>>(istream& is, Vector& obj);
};


#endif //WEEK07_VECTOR_H
