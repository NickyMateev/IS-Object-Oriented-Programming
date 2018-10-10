#pragma once
#include <iostream>
using namespace std;

class Person {
private:
    char* name;
    int age;
public:
    Person();
    Person(const char* name, int age);
    Person(const Person& other);
    Person& operator=(const Person& other);
    ~Person();

    const char* getName() const;
    int getAge() const;

    void setName(const char* name);
    void setAge(int age);

    void printInfo() const;
};