#include "stdafx.h"
#include "Person.h"


Person::Person()
{
	firstName = nullptr;
	middleName = nullptr;
	lastName = nullptr;
	EGN = new int[EGN_SIZE];
}

Person::Person(char* _firstName, char* _middleName, char* _lastName, int* _EGN)
{
	mystrcpy(firstName, _firstName);
	mystrcpy(middleName, _middleName);
	mystrcpy(lastName, _lastName);
	EGN = new int[EGN_SIZE];
	for (int i = 0; i < EGN_SIZE; ++i)
	{
		EGN[i] = _EGN[i];
	}
}

Person::~Person()
{
	delete[] firstName;
	delete[] middleName;
	delete[] lastName;
	delete[] EGN;
}

char* Person::getFirstName()
{
	return firstName;
}

char* Person::getMiddleName()
{
	return middleName;
}

char* Person::getLastName()
{
	return lastName;
}

int* Person::getEGN()
{
	return EGN;
}

void Person::setFirstName(char* newFirstName)
{
	delete[] firstName;
	mystrcpy(firstName, newFirstName);
}

void Person::setMiddleName(char* newMiddleName)
{
	delete[] middleName;
	mystrcpy(middleName, newMiddleName);
}

void Person::setLastName(char* newLastName)
{
	delete[] lastName;
	mystrcpy(lastName, newLastName);
}

void Person::setEGN(int* newEGN)
{
	// no need for 'delete[] EGN;', because we're just going to overwrite the old values manually
	for (int i = 0; i < EGN_SIZE; ++i)
	{
		EGN[i] = newEGN[i];
	}
}

void Person::copyPerson(Person& other)
{
	setFirstName(other.getFirstName());
	setMiddleName(other.getMiddleName());
	setLastName(other.getLastName());
	setEGN(other.getEGN());
}

void Person::printPerson()
{
	cout << "Person info:" << endl;
	cout << "\tFirst name: " << firstName << endl;
	cout << "\tMiddle name: " << middleName << endl;
	cout << "\tLast name: " << lastName << endl;
	cout << "\tEGN: ";
	for (int i = 0; i < EGN_SIZE; ++i)
	{
		cout << EGN[i];
	}
	cout << endl;
}
