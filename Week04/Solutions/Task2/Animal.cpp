//
// Created by nickym on 3/15/17.
//

#include "Animal.h"

Animal::Animal() {
    this->weight = 0;
    this->daysGrowing = 0;
    this->foodNeed = 0;
    this->waterNeed = 0;
    mystrcpy(this->name, "DEFAULT");
    this->currentFood = 0;
    this->currentWater = 0;
}

Animal::Animal(double weight, int daysGrowing, int foodNeed, int waterNeed, char *name) {
    this->weight = weight;
    this->daysGrowing = daysGrowing;
    this->foodNeed = foodNeed;
    this->waterNeed = waterNeed;
    mystrcpy(this->name, name);
    this->currentFood = foodNeed;
    this->currentWater = waterNeed;
}

Animal::Animal(const Animal &other) {
    this->weight = other.weight;
    this->daysGrowing = other.daysGrowing;
    this->foodNeed = other.foodNeed;
    this->waterNeed = other.waterNeed;
    mystrcpy(this->name, other.name);
    this->currentFood = other.foodNeed;
    this->currentWater = other.waterNeed;

}

Animal::~Animal() {
    delete[] this->name;
}

double Animal::getWeight() const {
    return this->weight;
}

int Animal::getDaysGrowing() const {
    return this->daysGrowing;
}

int Animal::getFoodNeed() const {
    return this->foodNeed;
}

int Animal::getWaterNeed() const {
    return this->waterNeed;
}

const char* Animal::getName() const {
    return this->name;
}

int Animal::getCurrentFood() const {
    return this->currentFood;
}

int Animal::getCurrentWater() const {
    return this->currentWater;
}

void Animal::setWeight(double weight) {
    this->weight = weight;
}

void Animal::setDaysGrowing(int daysGrowing) {
    this->daysGrowing = daysGrowing;
}

void Animal::setFoodNeed(int foodNeed) {
    this->foodNeed = foodNeed;
}

void Animal::setWaterNeed(int waterNeed) {
    this->waterNeed = waterNeed;
}

void Animal::setName(char *name) {
    mystrcpy(this->name, name);
}

void Animal::setCurrentFood(int currentFood) {
    this->currentFood = currentFood;
}

void Animal::setCurrentWater(int currentWater) {
    this->currentWater = currentWater;
}

void Animal::needs() {
    cout << "\tFood needs for a single day:" << this->foodNeed << "kg" << endl;
    cout << "\tWater needs for a single day:" << this->waterNeed << " liters" << endl;
}

void Animal::description() {
    cout << "Animal information:" << endl;
    cout << "\tName: " << this->name << endl;
    cout << "\tWeight: " << this->weight << "kg" << endl;
    cout << "\tDays growing: " << this->daysGrowing << " days" << endl;
    needs();
    cout << "\tCurrent food: " << this->currentFood << "kg" << endl;
    cout << "\tCurrent water: " << this->currentWater << " liters" << endl;
}

void Animal::feed(int foodAmount, int waterAmount) {
    if(foodAmount > 0)
    {
        this->currentFood += foodAmount;
    }

    if(waterAmount > 0)
    {
        this->currentWater += waterAmount;
    }
}
