//
// Created by Mateev, Nikolay on 4/27/17.
//

#ifndef EXAM1_COACH_H
#define EXAM1_COACH_H
#include <iostream>
#include "myFunctions.h"
using namespace std;

const char* DEFAULT_NAME = "DEFAULT_NAME";

class Coach {
private:
    char* name;
    int age;
    int yearsExperience;
    double salary;

    void copy(const Coach& other);
    void destroy();
public:
    Coach();
    Coach(const char* name, int age, int yearsExperience, double salary);
    Coach(const Coach& other);
    Coach& operator=(const Coach& other);
    ~Coach();

    const char* getName() const;
    int getAge() const;
    int getYearsExperience() const;
    double getSalary() const;

    void setName(const char* name);
    void setAge(int age);
    void setYearsExperience(int yearsExperience);
    void setSalary(double salary);

    friend ostream& operator<<(ostream& os, const Coach& obj);
};


#endif //EXAM1_COACH_H
