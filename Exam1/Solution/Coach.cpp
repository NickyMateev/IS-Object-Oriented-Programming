//
// Created by Mateev, Nikolay on 4/27/17.
//

#include "Coach.h"

void Coach::copy(const Coach &other) {
    mystrcpy(this->name, other.name);
    this->age = other.age;
    this->yearsExperience = other.yearsExperience;
    this->salary = other.salary;
}

void Coach::destroy() {
    delete[] this->name;
}

Coach::Coach() {
    mystrcpy(this->name, DEFAULT_NAME);
    this->age = 0;
    this->yearsExperience = 0;
    this->salary = 0;
}

Coach::Coach(const char* name, int age, int yearsExperience, double salary) {
    mystrcpy(this->name, name);
    this->age = (age >= 0) ? age : 0;
    this->yearsExperience = (yearsExperience >= 0) ? yearsExperience : 0;
    this->salary = (salary >= 0) ? salary : 0;
}

Coach::Coach(const Coach &other) {
    copy(other);
}

Coach &Coach::operator=(const Coach &other) {
    if(this != &other) {
        destroy();
        copy(other);
    }
    return *this;
}

Coach::~Coach() {
    destroy();
}

const char* Coach::getName() const {
    return this->name;
}

int Coach::getAge() const {
    return this->age;
}

int Coach::getYearsExperience() const {
    return this->yearsExperience;
}

double Coach::getSalary() const {
    return this->salary;
}

void Coach::setName(const char* name) {
    delete[] this->name;
    mystrcpy(this->name, name);
}

void Coach::setAge(int age) {
    if(age >= 0) {
        this->age = age;
    }
}

void Coach::setYearsExperience(int yearsExperience) {
    if(yearsExperience >= 0){
        this->yearsExperience = yearsExperience;
    }
}

void Coach::setSalary(double salary) {
    if(salary >= 0) {
        this->salary = salary;
    }
}

ostream& operator<<(ostream& os, const Coach& obj) {
    os << "Coach info:" << endl;
    os << "Name: " << obj.name << endl;
    os << "Age: " << obj.age << endl;
    os << "Years experience: " << obj.yearsExperience << endl;
    os << "Salary: $" << obj.salary;

    return os;
}
