#pragma once
#include <iostream>
using namespace std;

const int SIZE = 100;

class Smartphone {
private:
    char* brand;
    char* model;
    double price;

    void copy(const Smartphone& other);
    void destroy();
public:
    Smartphone();
    Smartphone(const char* brand, const char* model, double price);
    Smartphone(const Smartphone& other);
    Smartphone& operator=(const Smartphone& other);
    ~Smartphone();

    const char* getBrand() const;
    const char* getModel() const;
    double getPrice() const;

    void setBrand(const char* brand);
    void setModel(const char* model);
    void setPrice(double price);

    friend ostream& operator<<(ostream& os, const Smartphone& smartphone);
    friend istream& operator>>(istream& is, Smartphone& smartphone);
};