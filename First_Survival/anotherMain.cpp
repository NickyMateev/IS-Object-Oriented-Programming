#include <iostream>
using namespace std;

class Person {
private:
    char* name;
    void copy(const Person& other) {
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
    }
    void destroy() {
        delete[] this->name;
    }
public:
    Person() {
        this->name = NULL;
    }

    Person(const char* name) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    Person(const Person& other) {
        copy(other);
    }

    Person& operator=(const Person& other) {
        if(this != &other) {
            destroy();
            copy(other);
        }
        return *this;
    }

    ~Person() {
        destroy();
    }

    friend ostream& operator<<(ostream& os, const Person& other) {
        os << "(Name: " << other.name << ")";
        return os;
    }
};

const int DEFAULT_CAP = 16;

class Company {
private:
    Person* employees;
    int size;
    int capacity;

    void copy(const Company& other) {
       this->size = other.size;
        this->capacity = other.capacity;
        this->employees = new Person[this->capacity];
        for(int i = 0; i < size; i++) {
            this->employees[i] = other.employees[i];
        } 
    }

    void destroy() {
        delete[] this->employees;
    }
public:
    Company() {
        this->employees = new Person[DEFAULT_CAP];
        this->size = 0;
        this->capacity = DEFAULT_CAP;
    }

    Company(Person* employees, int size) {
        this->size = size;
        this->capacity = 2 * size;
        this->employees = new Person[this->capacity];
        for(int i = 0; i < size; i++) {
            this->employees[i] = employees[i];
        }
    }

    Company(const Company& other) {
        copy(other);
    }

    Company& operator=(const Company& other) {
        if(this != &other) {
            destroy();
            copy(other);
        }
        return *this;
    }

    ~Company() {
        destroy();
    }

    Person* getEmployees() const {
        return this->employees;
    }

    int getSize() const {
        return this->size;
    }
};

int main() {
    Person p("Mirka");
    Person p2("Nuray");
    cout << p << endl;
    cout << p2 << endl;
    cout << endl << endl << endl;

    Person emps[2] = {p, p2};
    Company company(emps, 2);

    Person* employees = company.getEmployees();
    int numberOfEmployees = company.getSize();

    for(int i  = 0; i < numberOfEmployees; i++) {
        cout << employees[i] << endl;
    }

    return 0;
}