//
// Created by Mateev, Nikolay on 4/12/17.
//

#include "Vector.h"

const int DEFAULT_CAP = 16;

void Vector::copy(const Vector& other) {
    this->container = new int[other.capacity];
    for (int i = 0; i < other.size; ++i) {
       this->container[i] = other.container[i];
    }
    this->size = other.size;
    this->capacity = other.capacity;
}

void Vector::destroy() {
    delete[] container;
}

void Vector::resize(int newCapacity) {
    int* temp = new int[newCapacity];
    for (int i = 0; i < this->size; ++i) {
        temp[i] = this->container[i];
    }

    delete[] this->container;
    this->container = temp;
    this->capacity = newCapacity;
}

void Vector::removeAt(int index) {
    for (int j = index; j < this->size - 1; ++j) {
        this->container[j] = this->container[j + 1];
    }

    this->size--;
}

void Vector::swap(int& lhs, int& rhs) {
    int temp = lhs;
    lhs = rhs;
    rhs = temp;
}


Vector::Vector() {
    this->container = new int[DEFAULT_CAP];
    this->size = 0;
    this->capacity = DEFAULT_CAP;
}

Vector::Vector(const int* arr, int size) {
    if(size >= DEFAULT_CAP)
    {
        this->capacity = size * 2;
    }
    else
    {
        this->capacity = DEFAULT_CAP;
    }

    this->container = new int[this->capacity];
    for (int i = 0; i < size; ++i) {
        this->container[i] = arr[i];
    }
    this->size = size;
}

Vector::Vector(const Vector& other) {
    copy(other);
}

Vector& Vector::operator=(const Vector &other) {
    if(this != &other) {
        destroy();
        copy(other);
    }
    return *this;
}

Vector::~Vector() {
    destroy();
}

int Vector::getSize() const {
    return this->size;
}

int Vector::getCapacity() const {
    return this->capacity;
}

bool Vector::isEmpty() const {
    return (this->size == 0);
}

void Vector::sort(bool increasing) {
    for (int i = 0; i < this->size - 1; ++i) {
        for (int j = 0; j < this->size - i - 1; ++j) {
           if(increasing) {
                if(this->container[i] > this->container[i + 1]) {
                    swap(this->container[i], this->container[i + 1]);
                }
           } else {
               if(this->container[i] < this->container[i + 1]) {
                   swap(this->container[i], this->container[i + 1]);
               }

           }
        }

    }
}

bool Vector::isSorted(bool increasing) const {
    if(increasing) {
        for (int i = 0; i < this->size - 1; ++i) {
           if(this->container[i] > this->container[i + 1]) {
                return false;
           }
        }
    } else {
        for (int i = 0; i < this->size - 1; ++i) {
            if(this->container[i] < this->container[i + 1]) {
                return false;
            }
        }
    }

    return true;
}

int Vector::getAt(int index) {
    assert(("Invalid index!", index >= 0 && index < this->size));

    return this->container[index];
}

void Vector::setAt(int index, int element) {
    assert(("Invalid index!", index >= 0 && index < this->size));

    this->container[index] = element;
}

void Vector::add(int element) {
    if(this->size == this->capacity) {
        resize(this->capacity * 2);
    }

    this->container[this->size] = element;
    this->size++;
}

void Vector::remove(int element) {
    for (int i = 0; i < this->size; ++i) {
       if(this->container[i] != element) {
           continue;
       } else {
           removeAt(i);
           break; // breaking so that the loop doesn't pointlessly keep looping till the reaching the end condition
       }
    }
}

Vector& Vector::operator+=(const Vector& other) {
    for (int i = 0; i < this->size && i < other.size; ++i) {
       this->container[i] += other.container[i];
    }

    return *this;
}

Vector& Vector::operator-=(const Vector& other) {
    for (int i = 0; i < this->size && i < other.size; ++i) {
        this->container[i] -= other.container[i];
    }

    return *this;
}

Vector& Vector::operator*=(const Vector& other) {
    for (int i = 0; i < this->size && i < other.size; ++i) {
        this->container[i] *= other.container[i];
    }

    return *this;
}

Vector& Vector::operator/=(const Vector& other) {
    for (int i = 0; i < this->size && i < other.size; ++i) {
        this->container[i] /= other.container[i];
    }

    return *this;
}

Vector operator+(const Vector& v1, const Vector& v2) {
    Vector newVector(v1);
    newVector += v2;

    return newVector;
}

Vector operator-(const Vector& v1, const Vector& v2) {
    Vector newVector(v1);
    newVector -= v2;

    return newVector;
}

Vector operator*(const Vector& v1, const Vector& v2) {
    Vector newVector(v1);
    newVector *= v2;

    return newVector;
}

Vector operator/(const Vector& v1, const Vector& v2) {
    Vector newVector(v1);
    newVector /= v2;

    return newVector;
}


const int Vector::operator[](int index) const {
    assert(("Invalid index!", index >= 0 && index < this->size));

    return this->container[index];
}

int& Vector::operator[](int index) {
    assert(("Invalid index!", index >= 0 && index < this->size));

    return this->container[index];
}

ostream& operator<<(ostream& os, const Vector& obj) {
    os << "[";
    for (int i = 0; i < obj.size; ++i) {
       os << obj.container[i];
        if(i != obj.size - 1) {
            os << ", ";
        }
    }
    os << "]";

    return os;
}

istream& operator>>(istream& is, Vector& obj) {
    cout << "Vector size: " << obj.size << endl;
    for (int i = 0; i < obj.size; ++i) {
        cout << "element[" << i << "] = ";
        is >> obj.container[i];
    }

    return is;
}
