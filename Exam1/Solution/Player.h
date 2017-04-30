//
// Created by Mateev, Nikolay on 4/27/17.
//

#ifndef EXAM1_PLAYER_H
#define EXAM1_PLAYER_H
#include <iostream>
#include <cstring>
#include "myFunctions.h"
using namespace std;

const char* DEFAULT_NAME = "DEFAULT_NAME";


class Player {
private:
    char* name;
    int age;
    double ppg;
    double apg;
    double rpg;
    double salary;

    void copy(const Player& other);
    void destroy();
public:
    Player();
    Player(const char* name, int age, double ppg, double apg, double rpg, double salary);
    Player(const Player& other);
    Player& operator=(const Player& other);
    ~Player();

    const char* getName() const;
    int getAge() const;
    double getPPG() const;
    double getAPG() const;
    double getRPG() const;
    double getSalary() const;

    void setName(const char* name);
    void setAge(int age);
    void setPPG(double ppg);
    void setAPG(double apg);
    void setRPG(double rpg);
    void setSalary(double salary);

    friend ostream& operator<<(ostream& os, const Player& obj);

    bool operator==(const Player& other);
};


#endif //EXAM1_PLAYER_H
