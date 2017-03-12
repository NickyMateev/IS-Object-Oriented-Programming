#pragma once
#include "Person.h"
#include "Currency.h"

class BankAccount
{
private:
	// Fields:
	Person owner;
	char* IBAN;
	double balance;
	Currency currency;
public:
	// Constructors & destructor:
	BankAccount();
	BankAccount(Person& _owner, char* _IBAN, double _balance, Currency _currency);
	~BankAccount();

	// Getters & setters:
	Person& getOwner();
	char* getIBAN();
	double getBalance();
	Currency getCurrency();

	void setOwner(Person& newOwner);
	void setIBAN(char* newIBAN);
	void setBalance(double newBalance);
	void setCurrency(Currency newCurrency);

	// Other methods required by the task:
	void deposit(double amount);
	void withdraw(double amount);
};
