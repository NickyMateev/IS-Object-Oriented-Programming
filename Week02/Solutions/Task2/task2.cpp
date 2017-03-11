#include "stdafx.h"
#include <iostream>
using namespace std;

const int SIZE = 100;
const int EGN_SIZE = 10;
const int DEFAULT_CAPACITY = 1000;
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
	// Constructors & Destructor:
	BankAccount();
	BankAccount(Person _owner, char* _IBAN, double _balance, Currency _currency);
	~BankAccount();


	// Getters & setters:
	Person getOwner();
	char* getIBAN();
	double getBalance();
	Currency getCurrency();

	void setOwner(Person newOwner);
	void setIBAN(char* newIBAN);
	void setBalance(double newBalance);
	void setCurrency(Currency newCurrency);

	// Methods required for current task:
	void deposit(double amount);
	void withdraw(double amount);

	void printBankAccountInfo();
};

class Bank
{
private:
	char name[SIZE];
	BankAccount bankAccounts[DEFAULT_CAPACITY];
	int bankAccountsCount; // this field will keep track of the current number of accounts in the bankAccounts array
	Person employees[DEFAULT_CAPACITY];
	int employeesCount; // this field will keep track of the current number of employees in the employees array

public:
	// Constructor & Destructor:
	Bank(char* _name, BankAccount* _bankAccounts, int _bankAccountsCount, Person* _employees, int _employeesCount);
	~Bank();

	// Getters & setters:
	char* getName();
	BankAccount* getBankAccounts();
	int getBankAccountsCount();
	Person* getEmployees();
	int getEmployeesCount();

	void setName(char* newName);
	void setBankAccounts(BankAccount* newBankAccounts, int newBankAccountsCount);
	void setEmployees(Person* newEmployees, int newEmployeesCount);

	// NOTE: It will not be correct to have setters for bankAccountsCount and employeesCount, because the values of those fields should only be manipulated from within the class

	// Methods required for the current task:
	int getBankAccountIndex(int* EGN);
	double getTotalBalance(int* EGN);
	bool isEmployee(Person person);
	int getEmployeesWithAccountsCount();
	void deposit(char* IBAN, double amount);
	void withdraw(char* IBAN, double amount);
	void printBankAccountsInfo(int* EGN);
};


// *** Functions related to the Person structure: ***
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
	cout << "\tFirst name: " << person.firstName << endl;
	cout << "\tMiddle name: " << person.middleName << endl;
	cout << "\tLast name: " << person.lastName << endl;
	cout << "\tEGN: ";
	for (int i = 0; i < EGN_SIZE; ++i)
	{
		cout << person.EGN[i];
	}
	cout << "\n\n";
}

// *** Implementation of the BankAccount class: ***
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
	if (balance - amount >= 0)
	{
		balance -= amount;
	}
}

void BankAccount::printBankAccountInfo()
{
	cout << "Bank Account info:" << endl;
	printPerson(owner);
	cout << "IBAN: ";
	for (int i = 0; IBAN[i] != '\0'; ++i)
	{
		cout << IBAN[i];
	}
	cout << endl;
	cout << "Balance: " << balance << endl;
	cout << "Currency: " << currency << endl;
}


// *** Implementation of the Bank class: ***

// HELPER FUNCTION(needed during construction and in setter later in the code):
void copyBankAccount(BankAccount& dest, BankAccount src)
{
	dest.setOwner(src.getOwner());
	dest.setIBAN(src.getIBAN());
	dest.setBalance(src.getBalance());
	dest.setCurrency(src.getCurrency());
}


Bank::Bank(char* _name, BankAccount* _bankAccounts, int _bankAccountsCount, Person* _employees, int _employeesCount)
{
	strcpy_s(name, SIZE, _name);
	for (int i = 0; i < _bankAccountsCount; ++i)
	{
		copyBankAccount(bankAccounts[i], _bankAccounts[i]);
	}
	bankAccountsCount = _bankAccountsCount;
	for (int i = 0; i < _employeesCount; ++i)
	{
		initPerson(employees[i], _employees[i].firstName, _employees[i].middleName, _employees[i].lastName, _employees[i].EGN);
	}
	employeesCount = _employeesCount;
}

Bank::~Bank()
{
	// nothing to write here because we haven't used any dynamic memory
	// so there's nothing to destroy(delete dynamic memory)
}

char* Bank::getName()
{
	return name;
}

BankAccount* Bank::getBankAccounts()
{
	return bankAccounts;
}

int Bank::getBankAccountsCount()
{
	return bankAccountsCount;
}

Person* Bank::getEmployees()
{
	return employees;
}

int Bank::getEmployeesCount()
{
	return employeesCount;
}

void Bank::setName(char* newName)
{
	strcpy_s(name, SIZE, newName);
}

void Bank::setBankAccounts(BankAccount* newBankAccounts, int newBankAccountsCount)
{
	for (int i = 0; i < newBankAccountsCount; ++i)
	{
		copyBankAccount(bankAccounts[i], newBankAccounts[i]);
	}
	bankAccountsCount = newBankAccountsCount;
}

void Bank::setEmployees(Person* newEmployees, int newEmployeesCount)
{
	for (int i = 0; i < newEmployeesCount; ++i)
	{
		initPerson(employees[i], newEmployees[i].firstName, newEmployees[i].middleName, newEmployees[i].lastName, newEmployees[i].EGN);
	}
	employeesCount = newEmployeesCount;
}

// HELPER FUNCTION:
bool isEGNSame(Person person, int* EGN)
{
	for (int i = 0; i < EGN_SIZE; ++i)
	{
		if(person.EGN[i] != EGN[i])
		{
			return false;
		}
	}

	return true;
}

int Bank::getBankAccountIndex(int* EGN)
{
	for (int i = 0; i < bankAccountsCount; ++i)
	{
		if(isEGNSame(bankAccounts[i].getOwner(), EGN))
		{
			return i;
		}
	}

	return -1; // if no owner of a bank account with the given EGN is found -> return -1
}

double Bank::getTotalBalance(int* EGN)
{
	double total = 0;
	for (int i = 0; i < bankAccountsCount; ++i)
	{
		if(isEGNSame(bankAccounts[i].getOwner(), EGN))
		{
			total += bankAccounts[i].getBalance();
		}
	}	

	return total;
}



// HELPER FUNCTION: 
bool isPersonSame(Person p1, Person p2)
{
	if(isEGNSame(p1, p2.EGN))
	{
		return (strcmp(p1.firstName, p2.firstName) == 0) && (strcmp(p1.middleName, p2.middleName) == 0) && (strcmp(p1.lastName, p2.lastName) == 0);
	}

	return false;
}

bool Bank::isEmployee(Person person)
{
	for (int i = 0; i < employeesCount; ++i)
	{
		if(isPersonSame(employees[i], person))
		{
			return true;
		}
	}

	return false;
}

int Bank::getEmployeesWithAccountsCount()
{
	int count = 0;
	for (int i = 0; i < employeesCount; ++i)
	{
		for (int j = 0; j < bankAccountsCount; ++j)
		{
			if(isPersonSame(employees[i], bankAccounts[j].getOwner()))
			{
				count++;
				break;
			}
		}
	}

	return count;
}

void Bank::deposit(char* IBAN, double amount)
{
	for (int i = 0; i < bankAccountsCount; ++i)
	{
		if(strcmp(bankAccounts[i].getIBAN(), IBAN) == 0)
		{
			bankAccounts[i].deposit(amount);
			return;
		}
	}

	cout << "Invalid IBAN, no such account!" << endl;
}

void Bank::withdraw(char* IBAN, double amount)
{
	for (int i = 0; i < bankAccountsCount; ++i)
	{
		if(strcmp(bankAccounts[i].getIBAN(), IBAN) == 0)
		{
			bankAccounts[i].withdraw(amount);
			return;
		}
	}

	cout << "Invalid IBAN, no such account!" << endl;
}

void Bank::printBankAccountsInfo(int* EGN)
{
	for (int i = 0; i < bankAccountsCount; ++i)
	{
		if(isEGNSame(bankAccounts[i].getOwner(), EGN))
		{
			bankAccounts[i].printBankAccountInfo();
		}
	}

}

int main()
{
	// Program demonstration:

	int egn1[] = { 1,2,3,4,5,6,7,8,9,1 };
	int egn2[] = { 1,2,3,4,5,6,7,8,9,2 };
	int egn3[] = { 1,2,3,4,5,6,7,8,9,3 };
	int egn4[] = { 1,2,3,4,5,6,7,8,9,4 };
	Person p1, p2, p3, p4;
	initPerson(p1, "First1", "Middle1", "Last1", egn1);
	initPerson(p2, "First2", "Middle2", "Last2", egn2);
	initPerson(p3, "First3", "Middle3", "Last3", egn3);
	initPerson(p4, "First4", "Middle4", "Last4", egn4);


	BankAccount ba1(p1, "123abc456DEF", 100000, DOLLARS);
	BankAccount ba2(p2, "223abc456DEF", 200000, EURO);
	BankAccount ba3(p3, "323abc456DEF", 300000, BGN);
	BankAccount ba4(p4, "424abc456DEF", 400000, BGN);

	const int ACC_SIZE = 4;
	BankAccount bankAccounts[ACC_SIZE];
	copyBankAccount(bankAccounts[0], ba1);
	copyBankAccount(bankAccounts[1], ba2);
	copyBankAccount(bankAccounts[2], ba3);
	copyBankAccount(bankAccounts[3], ba4);

	const int EMP_SIZE = 3;
	Person employees[EMP_SIZE];
	int egn5[] = { 1,2,3,4,5,6,7,8,9,5 };
	int egn6[] = { 1,2,3,4,5,6,7,8,9,6 };
	initPerson(employees[0], "First4", "Middle4", "Last4", egn5);
	initPerson(employees[1], "First5", "Middle5", "Last5", egn6);
	initPerson(employees[2], p4.firstName, p4.middleName, p4.lastName, egn4); // this means that we'll have an employee that also has a bank account in the bank

	Bank bank("The Next Great Bank", bankAccounts, ACC_SIZE, employees, EMP_SIZE);
	double totalBalance = bank.getTotalBalance(egn3);
	cout << "Total balance: " << totalBalance << endl; // should be 300 000
	cout << "\nEmployees with bank accounts in the bank: " << bank.getEmployeesWithAccountsCount() << endl; // should be 1
	
	char* iban = "223abc456DEF";
	cout << "\nDepositing 123$ to account with IBAN - '" << iban << "'..." << endl;
	bank.deposit(iban, 123); // should become 200 123

	cout << "\nPrinting the bank account info of account of owner with specific EGN..." << endl;
	bank.printBankAccountsInfo(egn2);

	return 0;
}
