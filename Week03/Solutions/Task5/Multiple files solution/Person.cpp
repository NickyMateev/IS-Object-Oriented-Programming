#include "Person.h"

Person::Person() {
    this->name = NULL;
    this->age = 0;
}

Person::Person(const char* name, int age) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->age = age;
}

Person::Person(const Person& other) {
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
    this->age = other.age;
}

Person& Person::operator=(const Person& other) {
    if (this != &other) {
        delete[] this->name;
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
        this->age = other.age;
    }
    return *this;
}

Person::~Person() {
    delete[] this->name;
}

const char* Person::getName() const {
    return this->name;
}

int Person::getAge() const {
    return this->age;
}

void Person::setName(const char* name) {
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

void Person::setAge(int age) {
    this->age = age;
}

// a much better approach would be to override operator<<
void Person::printInfo() const { 
    cout << "Name: " << this->name << endl;
    cout << "Age: " << this->age << endl;
}