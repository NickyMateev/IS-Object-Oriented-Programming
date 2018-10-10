// ConsoleApplication16.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

/*
 * NOTE: Dynamic memory deallocation should be taken care of.
 * This code snippet is only intended for the purposes
 * of demonstrating the concepts of inheritance and
 * the usage of virtual functions with regards to polymorphysm.
 */

class Animal {
public:
	virtual void makeSound() {
		cout << "I AM ROBOT" << endl;
	}
};

class Cat : public Animal {
public:
	 void makeSound() {
		cout << "MEOW" << endl;
	}
};

class Dog : public Animal {
public:
	void makeSound() {
		cout << "WOOF" << endl;
	}
};

class Chicken : public Animal {
public:
	void makeSound() {
		cout << "CHICK" << endl;
	}
};

const int SIZE = 10;

class Zoo {
private:
	Animal* animals[SIZE];

	int size;
public:
	Zoo(Animal** animals, int size) {
		this->size = size;
		for (int i = 0; i < size; i++) {
			this->animals[i] = animals[i];
		}
	}

	void makeTheZooMoveItMoveIt() {
		for (int i = 0; i < size; i++) {
			animals[i]->makeSound();
		}
	}
};

class Vehicle {
	int x;
	int y;
	int z;
public:
	Vehicle() {
		this->x = 0;
		this->y= 0;
		this->z = 0;
	}
	Vehicle(int x, int y, int z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
};

class Bicycle : public Vehicle {
	int a;
	int b;
public:
	Bicycle(int x, int y, int z, int a, int b) : Vehicle(x, y, z) {
		this->a = a;
		this->b = b;
	}
};

int main()
{
	Animal* animalKingdom[3];
	animalKingdom[0] = new Dog();
	animalKingdom[1] = new Cat();
	animalKingdom[2] = new Chicken();

	Zoo zoo(animalKingdom, 3);
	zoo.makeTheZooMoveItMoveIt();

	Bicycle b(1, 2, 3, 4, 5);

    return 0;
}

