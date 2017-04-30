//
// Created by Mateev, Nikolay on 4/27/17.
//

#ifndef EXAM1_STAFFMEMBER_H
#define EXAM1_STAFFMEMBER_H
#include <iostream>
#include <cstring>
#include "myFunctions.h"
using namespace std;

const char* DEFAULT_NAME = "DEFAULT_NAME";

class StaffMember {
private:
    char* name;
    double salary;

    void copy(const StaffMember& other);
    void destroy();
public:
    StaffMember();
    StaffMember(const char* name, double salary);
    StaffMember(const StaffMember& other);
    StaffMember& operator=(const StaffMember& other);
    ~StaffMember();

    const char* getName() const;
    double getSalary() const;

    void setName(const char* name);
    void setSalary(double salary);

    friend ostream& operator<<(ostream& os, const StaffMember& obj);

    bool operator==(const StaffMember& other);
};


#endif //EXAM1_STAFFMEMBER_H
