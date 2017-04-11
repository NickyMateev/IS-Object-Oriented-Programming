//
// Created by Mateev, Nikolay on 4/11/17.
//

#include "Employee.h"

void Employee::copy(const Employee &other) {
    mystrcpy(this->name, other.name);
    this->age = other.age;
    this->monthlySalary = other.monthlySalary;
    this->employeePosition = other.employeePosition;
}

void Employee::destroy() {
    delete[] this->name;
}

Employee::Employee() {
    this->name = NULL;
    this->age = 0;
    this->monthlySalary = 0;
    this->employeePosition = EmployeePosition::PROGRAMMER;
}

Employee::Employee(char* name, int age, double monthlySalary, EmployeePosition employeePosition) {
    mystrcpy(this->name, name);

    if(age < 0) {
        this->age = 0;
    } else {
        this->age = age;
    }

    if(monthlySalary < 0) {
        this->monthlySalary = 0;
    } else {
        this->monthlySalary = monthlySalary;
    }

    this->employeePosition = employeePosition;
}

Employee::Employee(const Employee &other) {
    copy(other);
}

Employee &Employee::operator=(const Employee &other) {
    if(this != &other) {
        destroy();
        copy(other);
    }

    return *this;
}

Employee::~Employee() {
    destroy();
}

const char* Employee::getName() const {
    return this->name;
}

int Employee::getAge() const {
    return this->age;
}

double Employee::getMonthlySalary() const {
    return this->monthlySalary;
}

EmployeePosition Employee::getEmployeePosition() const {
    return this->employeePosition;
}

void Employee::setName(const char* name) {
    delete[] this->name;
    mystrcpy(this->name, name);
}

void Employee::setAge(int age) {
    if(age >= 0) {
        this->age = age;
    }
}

void Employee::setMonthlySalary(double monthlySalary) {
    if(monthlySalary >= 0) {
        this->monthlySalary = monthlySalary;
    }
}

void Employee::setEmployeePosition(EmployeePosition employeePosition) {
    this->employeePosition = employeePosition;
}

double Employee::calculateAnnualSalary() const {
    return (this->monthlySalary * 12);
}

void Employee::increaseSalary(int percent) {
    if(percent >= 0) {
        this->monthlySalary *= ((100 + percent) / 100);
    }
}

void Employee::decreaseSalary(int percent) {
    if(percent >= 0) {
        this->monthlySalary *= ((100 - percent) / 100);
    }
}

