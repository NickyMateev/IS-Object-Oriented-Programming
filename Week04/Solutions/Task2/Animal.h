//
// Created by nickym on 3/15/17.
//

#pragma once
#include <iostream>
#include "myFunctions.h"
using namespace std;

class Animal {
private:
    double weight;
    int daysGrowing;
    int foodNeed;
    int waterNeed;
    int currentFood;
    int currentWater;
    char* name;
public:
    Animal();
    Animal(double weight, int daysGrowing, int foodNeed, int waterNeed, char* name);
    Animal(const Animal& other);
    ~Animal();

    double getWeight() const;
    int getDaysGrowing() const;
    int getFoodNeed() const;
    int getWaterNeed() const;
    const char* getName() const;
    int getCurrentFood() const;
    int getCurrentWater() const;

    void setWeight(double weight);
    void setDaysGrowing(int daysGrowing);
    void setFoodNeed(int foodNeed);
    void setWaterNeed(int waterNeed);
    void setName(char* name);
    void setCurrentFood(int currentFood);
    void setCurrentWater(int currentWater);

    void needs();
    void description();
    void feed(int foodAmount, int waterAmount);
};

