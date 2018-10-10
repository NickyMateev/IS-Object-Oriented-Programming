#include <iostream>
#include <fstream>
using namespace std;

class Point {
private:
    int x;
    int y;
    char* firstName;
    char* middleName;
    char* lastName;

    void copy(const Point& other) {
        this->x = other.x;
        this->y = other.y;

        this->firstName = new char[strlen(other.firstName) + 1];
        strcpy(this->firstName , other.firstName);

        this->middleName = new char[strlen(other.middleName) + 1];
        strcpy(this->middleName , other.middleName);

        this->lastName = new char[strlen(other.lastName) + 1];
        strcpy(this->lastName , other.lastName);
    }

    void destroy() {
        delete[] this->firstName;
        delete[] this->middleName;
        delete[] this->lastName;
    }

    void copyName(char* destName, char* srcName1, char* srcName2) {
        int j = 0;
        for(int i = 0; srcName1[i] != '\0'; i++) {
            destName[j++] = srcName1[i];
        }
        destName[j++] = ' ';
        destName[j++] = '<';
        destName[j++] = '3';
        destName[j++] = ' ';

        for(int i = 0; srcName2[i] != '\0'; i++) {
            destName[j++] = srcName2[i];
        }
        destName[j] = '\0';
    }
public:
    Point() {
        this->x = 0;
        this->y = 0;
        this->firstName = NULL;
        this->middleName = NULL;
        this->lastName = NULL;
    }

    Point(int x, int y, const char* firstName, const char* middleName, const char* lastName) {
        this->x = x;
        this->y = y;

        this->firstName = new char[strlen(firstName) + 1];
        strcpy(this->firstName, firstName);

        this->middleName = new char[strlen(middleName) + 1];
        strcpy(this->middleName, middleName);

        this->lastName = new char[strlen(lastName) + 1];
        strcpy(this->lastName, lastName);
    }

    Point(const Point& other) {
        copy(other);
    }

    Point& operator=(const Point& other) {
        if (this != &other) {
            destroy(); 
            copy(other);
        }
        return *this;
    }

    ~Point() {
        destroy();
    }

    int getX() {
        return this->x;
    }

    int getY() {
        return this->y;
    }


    void setFirstName(const char* firstName) {
        delete[] this->firstName;
        this->firstName = new char[strlen(firstName) + 1];
        strcpy(this->firstName, firstName);
    }

    Point& operator+=(const Point& other) {
        this->x += other.x;
        this->y += other.y;

        char* temp = new char[strlen(this->firstName) + strlen(other.firstName) + 5];
        copyName(temp, this->firstName, other.firstName);
        delete[] this->firstName;
        this->firstName = temp;

        temp = new char[strlen(this->middleName) + strlen(other.middleName) + 5];
        copyName(temp, this->middleName, other.middleName);
        delete[] this->middleName;
        this->middleName= temp;

        temp = new char[strlen(this->lastName) + strlen(other.lastName) + 5];
        copyName(temp, this->lastName, other.lastName);
        delete[] this->lastName;
        this->lastName= temp;

        return *this;
    }

    friend Point operator+(const Point& p1, const Point& p2) {
        Point p3(p1);
        p3 += p2;
        return p3;
    }

    friend bool operator<(const Point& p1, const Point& p2) {
        if(p1.x < p2.x && p1.y < p2.y) {
            return true;
        } else {
            return false;
        }
    }
    
    friend bool operator>(const Point& p1, const Point& p2) {
            if(p1.x > p2.x && p1.y > p2.y) {
            return true;
        } else {
            return false;
        }
    }

    friend bool operator==(const Point& p1, const Point& p2) {
        return !(p1 < p2) && !(p1 > p2);
    }

    friend bool operator!=(const Point& p1, const Point& p2) {
        return !(p1 == p2);
    }
    

    friend ostream& operator<<(ostream& os, const Point& point) {
        os << point.firstName << endl << point.middleName << endl << point.lastName << endl 
        << ": (" << point.x << ", " << point.y << ")";
        return os;
    }
};

class Vector {
    private:
    int* elements;
    int size;
    public:
    Vector(int* elements, int size) {
        this->elements = new int[size];
        for(int i = 0; i < size; i++) { 
             this->elements[i] = elements[i];
        }
        this->size = size;
    }
    int* getElements() {
        return this->elements;
    }

    const int operator[](int index) const {
        return elements[index];
    }

    int& operator[](int index) {
        return elements[index];
    }

    friend ostream& operator<<(ostream& os, const Vector& other) {
        os << "[";
        for(int i = 0; i < other.size; i++) {
            os << other.elements[i];
            if (i != other.size - 1) {
                os << ", ";
            }
        }
        os << "]";
        return os;
    }
};

int main() {
    Point p1(1, 2, "Stoyan", "Ivanov", "Ivanov");
    Point p2(2, 4, "Nikolay", "Georgiev", "Georgiev");


    int arr[5] = {12, 5, 18, 8, 7};
    Vector v(arr, 5);
    v[2] = 42;
    cout << v << endl;

    return 0;
}