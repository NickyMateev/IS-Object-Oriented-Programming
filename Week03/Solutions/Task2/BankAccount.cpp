#include "BankAccount.h"

BankAccount::BankAccount()
{
	// owner is constructred automatically with the default Person constructor, no need to worry about it
	IBAN = NULL;
	balance = 0;
	currency = DOLLARS;
}

BankAccount::BankAccount(Person& _owner, char* _IBAN, double _balance, Currency _currency)
{
	owner.copyPerson(_owner);
	mystrcpy(IBAN, _IBAN);
	balance = _balance;
	currency = _currency;
}

BankAccount::~BankAccount()
{
	delete[] IBAN;
}

Person& BankAccount::getOwner()
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

void BankAccount::setOwner(Person& newOwner)
{
	owner.copyPerson(newOwner);
}

void BankAccount::setIBAN(char* newIBAN)
{
	delete[] IBAN;
	mystrcpy(IBAN, newIBAN);
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

void BankAccount::copyBankAccount(BankAccount& other)
{
	owner.copyPerson(other.getOwner());
	mystrcpy(IBAN, other.getIBAN());
	balance = other.getBalance();
	currency = other.getCurrency();
}

void BankAccount::printBankAccountInfo()
{
	cout << "Bank Account info:" << endl;
	owner.printPerson();
	cout << "IBAN: ";
	for (int i = 0; IBAN[i] != '\0'; ++i)
	{
		cout << IBAN[i];
	}
	cout << endl;
	cout << "Balance: " << balance << endl;
	cout << "Currency: " << currency << endl;
}

