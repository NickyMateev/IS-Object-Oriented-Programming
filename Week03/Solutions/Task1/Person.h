#pragma once
#include <iostream>
#include "myFunctions.h"

using namespace std;

const int EGN_SIZE = 10;

class Person
{
private:
	// Fields:
	char* firstName;
	char* middleName;
	char* lastName;
	int* EGN; 

public:
	// Constructors & destructor
	Person();
	Person(char* _firstName, char* _middleName, char* _lastName, int* _EGN);
	~Person();

	// Getters & setters:
	char* getFirstName();
	char* getMiddleName();
	char* getLastName();
	int* getEGN();

	void setFirstName(char* newFirstName);
	void setMiddleName(char* newMiddleName);
	void setLastName(char* newLastName);
	void setEGN(int* newEGN);

	// Other necessary methods:
	void copyPerson(Person& other); // we'll use this function when we want to copy another Person's data to our current Person object
	void printPerson(); // we'll use this function to print info about a Person object
};