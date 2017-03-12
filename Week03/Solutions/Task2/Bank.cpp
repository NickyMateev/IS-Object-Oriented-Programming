#include "Bank.h"

Bank::Bank(char* _name, BankAccount* _bankAccounts, int _bankAccountsCount, Person* _employees, int _employeesCount)
{
	mystrcpy(name, _name);

	bankAccounts = new BankAccount[_bankAccountsCount];
	for (int i = 0; i < _bankAccountsCount; ++i)
	{
		bankAccounts[i].copyBankAccount(_bankAccounts[i]);
	}
	bankAccountsCount = _bankAccountsCount;

	employees = new Person[_employeesCount];
	for (int i = 0; i < _employeesCount; ++i)
	{
		employees[i].copyPerson(_employees[i]);
	}
	employeesCount = _employeesCount;
	
}

Bank::~Bank()
{
	delete[] name;
	delete[] bankAccounts;
	delete[] employees;
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
	delete[] name;
	mystrcpy(name, newName);
}

void Bank::setBankAccounts(BankAccount* newBankAccounts, int newBankAccountsCount)
{
	if(bankAccountsCount != newBankAccountsCount)
	{
		delete[] bankAccounts;
		bankAccounts = new BankAccount[newBankAccountsCount];
	}

	for (int i = 0; i < newBankAccountsCount; ++i)
	{
		bankAccounts[i].copyBankAccount(newBankAccounts[i]);
	}
	bankAccountsCount = newBankAccountsCount;
}

void Bank::setEmployees(Person* newEmployees, int newEmployeesCount)
{
	if(employeesCount != newEmployeesCount)
	{
		delete[] employees;
		employees = new Person[newEmployeesCount];
	}

	for (int i = 0; i < newEmployeesCount; ++i)
	{
		employees[i].copyPerson(newEmployees[i]);
	}
	employeesCount = newEmployeesCount;
}

int Bank::getBankAccountIndex(int* EGN)
{
	for (int i = 0; i < bankAccountsCount; ++i)
	{
		if (bankAccounts[i].getOwner().isEGNSame(EGN))
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
		if (bankAccounts[i].getOwner().isEGNSame(EGN))
		{
			total += bankAccounts[i].getBalance();
		}
	}

	return total;
}

bool Bank::isEmployee(Person& person)
{
	for (int i = 0; i < employeesCount; ++i)
	{
		if (employees[i].isPersonSame(person))
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
			if (employees[i].isPersonSame(bankAccounts[j].getOwner()))
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
		if (strcmp(bankAccounts[i].getIBAN(), IBAN) == 0)
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
		if (strcmp(bankAccounts[i].getIBAN(), IBAN) == 0)
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
		if (bankAccounts[i].getOwner().isEGNSame(EGN))
		{
			bankAccounts[i].printBankAccountInfo();
		}
	}
}
