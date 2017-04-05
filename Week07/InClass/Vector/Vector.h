//
// Created by nickym on 4/5/17.
//

#ifndef INCLASS_VECTOR_H
#define INCLASS_VECTOR_H


class Vector {
private:
    int* contaner;
    int size;
    int capacity;

    void resize(int newCapacity);
public:
    Vector();
    Vector(int* arr, int size);
    Vector(const Vector& other);
    Vector& operator=(const Vector& other);
    ~Vector();

    int getSize();
    int getCapacity();

    bool isEmpty();

    void sort(bool increasing);
    bool isSorted(bool increasing);

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
};


#endif //INCLASS_VECTOR_H
