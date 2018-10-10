#include <iostream>
using namespace std;

const int SIZE = 100;

class Smartphone {
private:
    char* brand;
    char* model;
    double price;

    void copy(const Smartphone& other) {
        this->brand = new char[strlen(other.brand) + 1];
        strcpy(this->brand, other.brand);
        this->model = new char[strlen(other.model) + 1];
        strcpy(this->model, other.model);
        this->price = other.price;
    }

    void destroy() {
        delete[] this->brand;
        delete[] this->model;
    }
public:
    Smartphone() {
        this->brand = NULL;
        this->model = NULL;
        this->price = 0;
    }

    Smartphone(const char* brand, const char* model, double price) {
        this->brand = new char[strlen(brand) + 1];
        strcpy(this->brand, brand);
        this->model = new char[strlen(model) + 1];
        strcpy(this->model, model);
        this->price = price;
    }

    Smartphone(const Smartphone& other) {
        copy(other);
    }

    Smartphone& operator=(const Smartphone& other) {
        if (this != &other) {
            destroy();
            copy(other);
        }
        return *this;
    }

    ~Smartphone() {
        destroy();
    }

    const char* getBrand() const {
        return this->brand;
    }

    const char* getModel() const {
        return this->model;
    }

    double getPrice() const {
        return this->price;
    }

    void setBrand(const char* brand) {
        delete[] this->brand;
        this->brand = new char[strlen(brand) + 1];
        strcpy(this->brand, brand);
    }

    void setModel(const char* model) {
        delete[] this->model;
        this->model = new char[strlen(model) + 1];
        strcpy(this->model, model);
    }


    void setPrice(double price) {
        this->price = price;
    }

    friend ostream& operator<<(ostream& os, const Smartphone& smartphone) {
        os << "Brand: " << smartphone.brand 
           << "\nModel: " << smartphone.model
           << "\nPrice: $" << smartphone.price;
        return os;
    }

    friend istream& operator>>(istream& is, Smartphone& smartphone) {
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
};

int main() {
    Smartphone smartphone1("Smartphone 1", "Model 1", 299.99);
    Smartphone smartphone2("Smartphone 2", "Model 2", 449.99);

    cout << smartphone1 << endl << endl;
    cout << smartphone2 << endl << endl;

    Smartphone smartphone3;
    cout << "Enter info for Smartphone 3:" << endl;
    cin >> smartphone3;

    cout << "\n*** Smartphone created ***\n" << smartphone3 << endl;
    return 0;
}