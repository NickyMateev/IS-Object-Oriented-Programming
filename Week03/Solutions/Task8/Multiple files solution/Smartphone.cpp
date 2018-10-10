#include "Smartphone.h"

void Smartphone::copy(const Smartphone& other) {
    this->brand = new char[strlen(other.brand) + 1];
    strcpy(this->brand, other.brand);
    this->model = new char[strlen(other.model) + 1];
    strcpy(this->model, other.model);
    this->price = other.price;
}

void Smartphone::destroy() {
    delete[] this->brand;
    delete[] this->model;
}

Smartphone::Smartphone() {
    this->brand = NULL;
    this->model = NULL;
    this->price = 0;
}

Smartphone::Smartphone(const char* brand, const char* model, double price) {
    this->brand = new char[strlen(brand) + 1];
    strcpy(this->brand, brand);
    this->model = new char[strlen(model) + 1];
    strcpy(this->model, model);
    this->price = price;
}

Smartphone::Smartphone(const Smartphone& other) {
    copy(other);
}

Smartphone& Smartphone::operator=(const Smartphone& other) {
    if (this != &other) {
        destroy();
        copy(other);
    }
    return *this;
}

Smartphone::~Smartphone() {
    destroy();
}

const char* Smartphone::getBrand() const {
    return this->brand;
}

const char* Smartphone::getModel() const {
    return this->model;
}

double Smartphone::getPrice() const {
    return this->price;
}

void Smartphone::setBrand(const char* brand) {
    delete[] this->brand;
    this->brand = new char[strlen(brand) + 1];
    strcpy(this->brand, brand);
}

void Smartphone::setModel(const char* model) {
    delete[] this->model;
    this->model = new char[strlen(model) + 1];
    strcpy(this->model, model);
}


void Smartphone::setPrice(double price) {
    this->price = price;
}

ostream& operator<<(ostream& os, const Smartphone& smartphone) {
    os << "Brand: " << smartphone.brand 
        << "\nModel: " << smartphone.model
        << "\nPrice: $" << smartphone.price;
    return os;
}

istream& operator>>(istream& is, Smartphone& smartphone) {
    delete[] smartphone.brand;
    delete[] smartphone.model;

    char* buffer = new char[SIZE];

    is.getline(buffer, SIZE);
    smartphone.brand = new char[strlen(buffer) + 1];
    strcpy(smartphone.brand, buffer);

    is.getline(buffer, SIZE);
    smartphone.model = new char[strlen(buffer) + 1];
    strcpy(smartphone.model, buffer);

    is >> smartphone.price;
    is.ignore();

    delete[] buffer;
    return is;
}