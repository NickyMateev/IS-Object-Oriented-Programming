//
// Created by nickym on 3/15/17.
//

#pragma once
#include <iostream>
#include "myFunctions.h"
using namespace std;

class Employee {
private:
    int id;
    char* firstName;
    char* lastName;
    int salary;
public:
    Employee();
    Employee(int id, char* firstName, char* lastName, int salary);
    Employee(const Employee& other);
    ~Employee();

    int getId() const;
    char* getFirstName() const;
    char* getLastName() const;
    int getSalary() const;

    void setId(int id);
    void setFirstName(char* firstName);
    void setLastName(char* lastName);
    void setSalary(int salary);

    int getAnnualSalary() const;
    void raiseSalary(int percent);
    void description();
};

