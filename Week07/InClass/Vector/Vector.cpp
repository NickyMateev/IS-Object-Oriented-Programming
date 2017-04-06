//
// Created by nickym on 4/5/17.
//

#include "Vector.h"

const int DEFAULT_CAP = 16;

void Vector::resize(int newCapacity) {
    int* temp = new int[newCapacity];
    for (int i = 0; i < this->size; ++i) {
       temp[i] = this->container[i];
    }

    delete[] this->container;
    this->container = temp;
    this->capacity = newCapacity;
}

Vector::Vector() {
    this->container = new int[DEFAULT_CAP];
    this->size = 0;
    this->capacity = DEFAULT_CAP;
}

Vector::Vector(int *arr, int size) {
    if(size >= DEFAULT_CAP)
    {
        this->capacity = size * 2;
    }
    this->container = new int[this->capacity];
    for (int i = 0; i < size; ++i) {
       this->container[i] = arr[i];
    }
    this->size = size;
}

Vector::Vector(const Vector &other) {

}

Vector &Vector::operator=(const Vector &other) {
    return <#initializer#>;
}

Vector::~Vector() {

}

int Vector::getSize() {
    return 0;
}

int Vector::getCapacity() {
    return 0;
}

bool Vector::isEmpty() {
    return false;
}

void Vector::sort(bool increasing) {

}

bool Vector::isSorted(bool increasing) {
    return false;
}

int Vector::getAt(int index) {
    return 0;
}

void Vector::setAt(int index, int element) {

}

void Vector::add(int element) {

}

void Vector::remove(int element) {

}

Vector &Vector::operator+=(const Vector &other) {
    return <#initializer#>;
}

Vector &Vector::operator-=(const Vector &other) {
    return <#initializer#>;
}

Vector &Vector::operator*=(const Vector &other) {
    return <#initializer#>;
}

Vector &Vector::operator/=(const Vector &other) {
    return <#initializer#>;
}

Vector operator+(const Vector &v1, const Vector &v2) {
    return Vector();
}

Vector operator-(const Vector &v1, const Vector &v2) {
    return Vector();
}

Vector operator*(const Vector &v1, const Vector &v2) {
    return Vector();
}

Vector operator/(const Vector &v1, const Vector &v2) {
    return Vector();
}
