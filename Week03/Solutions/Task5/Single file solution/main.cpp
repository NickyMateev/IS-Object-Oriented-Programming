#include <iostream>
using namespace std;

class Person {
private:
    char* name;
    int age;
public:
    Person() {
        this->name = NULL;
        this->age = 0;
    }

    Person(const char* name, int age) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->age = age;
    }

    Person(const Person& other) {
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
        this->age = other.age;
    }

    Person& operator=(const Person& other) {
        if (this != &other) {
            delete[] this->name;
            this->name = new char[strlen(other.name) + 1];
            strcpy(this->name, other.name);
            this->age = other.age;
        }
        return *this;
    }

    ~Person() {
        delete[] this->name;
    }

    const char* getName() const {
        return this->name;
    }

    int getAge() const {
        return this->age;
    }

    void setName(const char* name) {
        delete[] this->name;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    void setAge(int age) {
        this->age = age;
    }

    // a much better approach would be to override operator<<
    void printInfo() const { 
        cout << "Name: " << this->name << endl;
        cout << "Age: " << this->age << endl;
    }
};

int main() {
    Person person1("Stoyan Ivanov", 23);
    Person person2("Nikolay Mateev", 21);

    person1.printInfo();
    person2.printInfo();
    return 0;
}