#include "stdafx.h"
#include <iostream>
using namespace std;

const int SIZE = 100;
const int EGN_SIZE = 10;
int DEFAULT_EGN[] = { 0,0,0,0,0,0,0,0,0,0 };

enum Currency // enum is just another way to create a new type for us to use(similar to struct and classes)
{
	DOLLARS, // 0
	EURO,    // 1
	BGN      // 2
};

struct Person
{
	char firstName[SIZE];
	char middleName[SIZE];
	char lastName[SIZE];
	int EGN[EGN_SIZE];
};

class BankAccount
{
private:
	Person owner;
	char IBAN[SIZE];
	double balance;
	Currency currency;
public:
	BankAccount();
	BankAccount(Person _owner, char* _IBAN, double _balance, Currency _currency);
	~BankAccount();


	Person getOwner();
	char* getIBAN();
	double getBalance();
	Currency getCurrency();

	void setOwner(Person newOwner);
	void setIBAN(char* newIBAN);
	void setBalance(double newBalance);
	void setCurrency(Currency newCurrency);

	void deposit(double amount);
	void withdraw(double amount);
};


void initPerson(Person& person, char* firstName, char* middleName, char* lastName, int* EGN)
{
	strcpy_s(person.firstName, SIZE, firstName); // if you're not using VisualStudio, just write: strcpy(person.firstName, firstName) and analogous in every other case you use strcpy
	strcpy_s(person.middleName, SIZE, middleName);
	strcpy_s(person.lastName, SIZE, lastName);
	for (int i = 0; i < EGN_SIZE; ++i)
	{
		person.EGN[i] = EGN[i];
	}
}

// this function is not part of the requirements for the task, but it's here for testing purposes:
void printPerson(Person person) 
{
	cout << "Person info:" << endl;
	cout << "\tFirst name:" << person.firstName << endl;
	cout << "\tMiddle name:" << person.middleName << endl;
	cout << "\tLast name:" << person.lastName << endl;
	cout << "\tEGN: ";
	for (int i = 0; i < EGN_SIZE; ++i)
	{
		cout << person.EGN[i];
	}
	cout << "\n\n";
}

BankAccount::BankAccount()
{
	initPerson(owner, "DEFAULT", "DEFAULT", "DEFAULT", DEFAULT_EGN);
}

BankAccount::BankAccount(Person _owner, char* _IBAN, double _balance, Currency _currency)
{
	initPerson(owner, _owner.firstName, _owner.middleName, _owner.lastName, _owner.EGN);
	strcpy_s(IBAN, SIZE, _IBAN);
	balance = _balance;
	currency = _currency;
}

BankAccount::~BankAccount()
{
	// nothing to write here because we haven't used any dynamic memory
	// so there's nothing to destroy(delete dynamic memory)
}


Person BankAccount::getOwner()
{
	return owner;
}

char* BankAccount::getIBAN()
{
	return IBAN;
}


double BankAccount::getBalance()
{
	return balance;
}

Currency BankAccount::getCurrency()
{
	return currency;
}


void BankAccount::setOwner(Person newOwner)
{
	initPerson(owner, newOwner.firstName, newOwner.middleName, newOwner.lastName, newOwner.EGN);
}

void BankAccount::setIBAN(char* newIBAN)
{
	strcpy_s(IBAN, SIZE, newIBAN);
}


void BankAccount::setBalance(double newBalance)
{
	balance = newBalance;
}

void BankAccount::setCurrency(Currency newCurrency)
{
	currency = newCurrency;
}

void BankAccount::deposit(double amount)
{
	balance += amount;
}

void BankAccount::withdraw(double amount)
{
	if(balance - amount >= 0)
	{
		balance -= amount;
	}
}

int main()
{
	// Program demonstration:

	int egn[] = { 1,2,3,4,5,6,7,8,9,0};
	Person p;
	initPerson(p, "First", "Middle", "Last", egn);

	BankAccount ba(p, "123abc456DEF", 100000, DOLLARS);

	cout << "Bank account IBAN BEFORE change: " << ba.getIBAN() << endl;
	ba.setIBAN("ABC123");
	cout << "Bank account IBAN AFTER change: " << ba.getIBAN() << endl;
	cout << endl;

	cout << "Info about bank account owner: " << endl;
	printPerson(ba.getOwner());

	cout << "Bank account balance BEFORE withdraw: " << ba.getBalance() << endl;
	ba.withdraw(123);
	cout << "Bank account balance AFTER withdraw: " << ba.getBalance() << endl;

    return 0;
}

