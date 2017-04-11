//
// Created by Mateev, Nikolay on 4/11/17.
//

#include "Equipment.h"

void Equipment::copy(const Equipment &other) {
    mystrcpy(this->name, other.name);
    this->price = other.price;
    this->monthlyMaintenanceCost = other.monthlyMaintenanceCost;
}

void Equipment::destroy() {
    delete[] this->name;
}

Equipment::Equipment() {
    this->name = NULL;
    this->price = 0;
    this->monthlyMaintenanceCost = 0;
}

Equipment::Equipment(const char* name, double price, double monthlyMaintenanceCost) {
    mystrcpy(this->name, name);
    if(price < 0) {
        this->price = 0;
    } else {
        this->price = price;
    }

    if(monthlyMaintenanceCost < 0) {
        this->monthlyMaintenanceCost = 0;
    } else {
        this->monthlyMaintenanceCost = monthlyMaintenanceCost;
    }
}

Equipment::Equipment(const Equipment& other) {
    copy(other);
}

Equipment& Equipment::operator=(const Equipment& other) {
    if(this != &other) {
        destroy();
        copy(other);
    }
    return *this;
}

Equipment::~Equipment() {
    destroy();
}


const char* Equipment::getName() const {
    return this->name;
}

double Equipment::getPrice() const {
    return this->price;
}

double Equipment::getMonthlyMaintenanceCost() const {
    return this->monthlyMaintenanceCost;
}

void Equipment::setName(const char* name) {
    delete[] this->name;
    mystrcpy(this->name, name);
}

void Equipment::setPrice(double price) {
    if(price >= 0) {
        this->price = price;
    }
}


void Equipment::setMonthlyMaintenanceCost(double monthlyMaintenanceCost) {
    if(monthlyMaintenanceCost >= 0) {
        this->monthlyMaintenanceCost = monthlyMaintenanceCost;
    }
}
