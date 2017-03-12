#include "BankAccount.h"


int main()
{
	// Program demonstration:

	int egn[] = { 1,2,3,4,5,6,7,8,9,0 };
	Person p("First", "Middle", "Last", egn);

	BankAccount ba(p, "123abc456DEF", 100000, DOLLARS);

	cout << "Bank account IBAN BEFORE change: " << ba.getIBAN() << endl;
	ba.setIBAN("ABC123");
	cout << "Bank account IBAN AFTER change: " << ba.getIBAN() << endl;
	cout << endl;

	cout << "Info about bank account owner: " << endl;
	ba.getOwner().printPerson();

	cout << "Bank account balance BEFORE withdraw: " << ba.getBalance() << endl;
	ba.withdraw(123);
	cout << "Bank account balance AFTER withdraw: " << ba.getBalance() << endl;


    return 0;
}

