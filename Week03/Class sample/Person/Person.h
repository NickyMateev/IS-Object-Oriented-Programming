//
// Created by nickym on 3/8/17.
//

#pragma once
#include <iostream>
#include <cstring>

using namespace std;

class Person
{
private:
    char* firstName;
    char* middleName;
    char* lastName;
    int EGN;

    void mystrcpy(char*& dest, char* src);
public:
    Person();
    Person(char* newFirstName, char* newMiddleName, char* newLastName, int newEGN);
    ~Person();

    char* getFirstName();
    char* getMiddleName();
    char* getLastName();
    int getEGN();

    void setFirstName(char* newFirstName);
    void setMiddleName(char* newMiddleName);
    void setLastName(char* newLastName);
    void setEGN(int newEGN);
};

