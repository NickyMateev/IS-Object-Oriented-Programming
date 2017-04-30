//
// Created by Mateev, Nikolay on 4/27/17.
//

#include "StaffMember.h"


void StaffMember::copy(const StaffMember& other) {
    mystrcpy(this->name, other.name);
    this->salary = other.salary;
}

void StaffMember::destroy() {
    delete[] this->name;
}

StaffMember::StaffMember() {
    mystrcpy(this->name, DEFAULT_NAME);
    this->salary = 0;
}

StaffMember::StaffMember(const char* name, double salary) {
    mystrcpy(this->name, name);
    this->salary = (salary >= 0) ? salary : 0;
}

StaffMember::StaffMember(const StaffMember& other) {
    copy(other);
}

StaffMember& StaffMember::operator=(const StaffMember& other) {
    if(this != &other) {
        destroy();
        copy(other);
    }
    return *this;
}

StaffMember::~StaffMember() {
    destroy();
}

const char* StaffMember::getName() const {
    return this->name;
}

double StaffMember::getSalary() const {
    return this->salary;
}

void StaffMember::setName(const char* name) {
    delete[] this->name;
    mystrcpy(this->name, name);
}

void StaffMember::setSalary(double salary) {
    if(salary >= 0) {
        this->salary = salary;
    }
}

ostream& operator<<(ostream& os, const StaffMember& obj) {
    os << "Staff member info:" << endl;
    os << "Name: " << obj.name << endl;
    os << "Salary: $" << obj.salary;

    return os;
}

bool StaffMember::operator==(const StaffMember& other) {
    return (this->salary == other.salary) && (strcmp(this->name, other.name) == 0);
}
