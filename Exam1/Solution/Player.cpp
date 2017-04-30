//
// Created by Mateev, Nikolay on 4/27/17.
//

#include "Player.h"

void Player::copy(const Player &other) {
    mystrcpy(this->name, other.name);
    this->age = other.age;
    this->ppg = other.ppg;
    this->apg = other.apg;
    this->rpg = other.rpg;
    this->salary = other.salary;
}

void Player::destroy() {
    delete[] this->name;
}

Player::Player() {
    mystrcpy(this->name, DEFAULT_NAME);
    this->age = 0;
    this->ppg = 0;
    this->apg = 0;
    this->rpg = 0;
    this->salary = 0;
}

Player::Player(const char* name, int age, double ppg, double apg, double rpg, double salary) {
    mystrcpy(this->name, name);
    this->age = (age >= 0) ? age : 0;
    this->ppg = (ppg >= 0) ? ppg : 0;
    this->apg = (apg >= 0) ? apg: 0;
    this->rpg = (rpg >= 0) ? rpg : 0;
    this->salary = (salary >= 0) ? salary : 0;
}

Player::Player(const Player &other) {
    copy(other);
}

Player& Player::operator=(const Player& other) {
    if(this != &other) {
        destroy();
        copy(other);
    }
    return *this;
}

Player::~Player() {
    destroy();
}

const char* Player::getName() const {
    return this->name;
}

int Player::getAge() const {
    return this->age;
}

double Player::getPPG() const {
    return this->ppg;
}

double Player::getAPG() const {
    return this->apg;
}

double Player::getRPG() const {
    return this->rpg;
}

double Player::getSalary() const {
    return this->salary;
}

void Player::setName(const char* name) {
    delete[] this->name;
    mystrcpy(this->name, name);
}

void Player::setAge(int age) {
    if(age >= 0) {
        this->age = age;
    }
}

void Player::setPPG(double ppg) {
    if(ppg >= 0) {
        this->ppg = ppg;
    }
}

void Player::setAPG(double apg) {
    if(apg >= 0) {
        this->apg = apg;
    }
}

void Player::setRPG(double rpg) {
    if(rpg >= 0) {
        this->rpg = rpg;
    }
}

void Player::setSalary(double salary) {
    if(salary >= 0) {
        this->salary = salary;
    }
}

ostream& operator<<(ostream& os, const Player& obj) {
    os << "Player info:" << endl;
    os << "Name: " << obj.name << endl;
    os << "Age: " << obj.age << endl;
    os << "PPG: " << obj.ppg << endl;
    os << "APG: " << obj.apg << endl;
    os << "RPG: " << obj.rpg << endl;
    os << "Salary: $" << obj.salary;

    return os;
}

bool Player::operator==(const Player& other) {
    if(strcmp(this->name, other.name) == 0) {
        return (this->age == other.age) && (this->ppg == other.ppg) && (this->apg == other.apg) && (this->rpg == other.rpg) && (this->salary == other.salary);
    }

    return false;
}
