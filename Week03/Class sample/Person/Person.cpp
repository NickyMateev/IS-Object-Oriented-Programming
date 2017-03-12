//
// Created by nickym on 3/8/17.
//

#include "Person.h"

void Person::mystrcpy(char*& dest, char *src)
{
    int size = strlen(src) + 1;
    dest = new char[size];
    strcpy(dest, src);
}

Person::Person()
{
    cout << "Constructor called " << endl;
    firstName = nullptr;
    middleName = nullptr;
    lastName = nullptr;
    EGN = 0;
}

Person::Person(char* newFirstName, char* newMiddleName, char* newLastName, int newEGN)
{
    mystrcpy(firstName, newFirstName);
    mystrcpy(middleName, newMiddleName);
    mystrcpy(lastName, newLastName);
    EGN = newEGN;
}

Person::~Person()
{
    delete[] firstName;
    delete[] middleName;
    delete[] lastName;
}

char* Person::getFirstName()
{
    return firstName;
}

char* Person::getMiddleName()
{
    return middleName;
}

char* Person::getLastName()
{
    return lastName;
}

int Person::getEGN()
{
    return EGN;
}

void Person::setFirstName(char* newFirstName)
{
    delete[] firstName;
    mystrcpy(firstName, newFirstName);
}

void Person::setMiddleName(char* newMiddleName)
{
    delete[] middleName;
    mystrcpy(middleName, newMiddleName);
}

void Person::setLastName(char* newLastName)
{
    delete[] lastName;
    mystrcpy(lastName, newLastName);
}

void Person::setEGN(int newEGN)
{
   EGN = newEGN;
}
