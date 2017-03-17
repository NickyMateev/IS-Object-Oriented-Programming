//
// Created by nickym on 3/15/17.
//

#include "Employee.h"

Employee::Employee() {
    this->id = 0;
    mystrcpy(this->firstName, "Default");
    mystrcpy(this->lastName, "Default");
    this->salary = 0;
}

Employee::Employee(int id, char *firstName, char *lastName, int salary) {
    this->id = id;
    mystrcpy(this->firstName, firstName);
    mystrcpy(this->lastName,lastName);
    this->salary = salary;
}

Employee::Employee(const Employee &other) {
    this->id = other.id;
    mystrcpy(this->firstName, other.firstName);
    mystrcpy(this->lastName, other.lastName);
    this->salary = other.salary;
}

Employee::~Employee() {
    delete[] this->firstName;
    delete[] this->lastName;
}

int Employee::getId() const {
    return this->id;
}

char *Employee::getFirstName() const {
    return this->firstName;
}

char *Employee::getLastName() const {
    return this->lastName;
}

int Employee::getSalary() const {
    return this->salary;
}

void Employee::setId(int id) {
    this->id = id;
}

void Employee::setFirstName(char *firstName) {
    delete[] this->firstName;
    mystrcpy(this->firstName, firstName);
}

void Employee::setLastName(char *lastName) {
    delete[] this->lastName;
    mystrcpy(this->lastName, lastName);
}

void Employee::setSalary(int salary) {
    this->salary = salary;
}

int Employee::getAnnualSalary() const {
    return (this->salary * 12);
}

void Employee::raiseSalary(int percent) {
    double fraction = (100 + percent) / (double)100;

    this->salary *= fraction;
}

void Employee::description() {
    cout << "Employee info:" << endl;
    cout << "\tID: " << this->id << endl;
    cout << "\tFirst name: " << this->firstName << endl;
    cout << "\tLast name: " << this->lastName << endl;
    cout << "\tSalary: " << this->salary << endl;
}

