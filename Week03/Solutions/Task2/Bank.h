#pragma once
#include "BankAccount.h"

class Bank
{
private:
	// Fields:
	char* name;
	BankAccount* bankAccounts;
	int bankAccountsCount;
	Person* employees;
	int employeesCount;
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

	// Other methods required for the task:
	int getBankAccountIndex(int* EGN);
	double getTotalBalance(int* EGN);
	bool isEmployee(Person& person);
	int getEmployeesWithAccountsCount();
	void deposit(char* IBAN, double amount);
	void withdraw(char* IBAN, double amount);
	void printBankAccountsInfo(int* EGN);
};
