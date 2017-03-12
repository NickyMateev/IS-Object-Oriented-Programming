#include "Bank.h"


int main()
{
	// Program demonstration:

	int egn1[] = { 1,2,3,4,5,6,7,8,9,1 };
	int egn2[] = { 1,2,3,4,5,6,7,8,9,2 };
	int egn3[] = { 1,2,3,4,5,6,7,8,9,3 };
	int egn4[] = { 1,2,3,4,5,6,7,8,9,4 };

	Person p1("First1", "Middle1", "Last1", egn1);
	Person p2("First2", "Middle2", "Last2", egn2);
	Person p3("First3", "Middle3", "Last3", egn3);
	Person p4("First4", "Middle4", "Last4", egn4);


	BankAccount ba1(p1, "123abc456DEF", 100000, DOLLARS);
	BankAccount ba2(p2, "223abc456DEF", 200000, EURO);
	BankAccount ba3(p3, "323abc456DEF", 300000, BGN);
	BankAccount ba4(p4, "424abc456DEF", 400000, BGN);

	int accountsSize = 4;
	BankAccount* bankAccounts = new BankAccount[accountsSize]; // dynamic allocation of memory
	bankAccounts[0].copyBankAccount(ba1);
	bankAccounts[1].copyBankAccount(ba2);
	bankAccounts[2].copyBankAccount(ba3);
	bankAccounts[3].copyBankAccount(ba4);

	int employeesSize = 3;
	Person* employees = new Person[employeesSize]; // dynamic allocation of memory
	int egn5[] = { 1,2,3,4,5,6,7,8,9,5 };
	int egn6[] = { 1,2,3,4,5,6,7,8,9,6 };
	Person p5("First4", "Middle4", "Last4", egn5);
	Person p6("First5", "Middle5", "Last5", egn6);
	
	employees[0].copyPerson(p5);
	employees[1].copyPerson(p6);
	employees[2].copyPerson(p4); // this means that we'll have an employee that also has a bank account in the bank

	Bank bank("The Next Great Bank", bankAccounts, accountsSize, employees, employeesSize);
	double totalBalance = bank.getTotalBalance(egn3);
	cout << "Total balance: " << totalBalance << endl; // should be 300 000
	cout << "\nEmployees with bank accounts in the bank: " << bank.getEmployeesWithAccountsCount() << endl; // should be 1

	char* iban = "223abc456DEF";
	cout << "\nDepositing 123$ to account with IBAN - '" << iban << "'..." << endl;
	bank.deposit(iban, 123); // should become 200 123

	cout << "\nPrinting the bank account info of account owner with specific EGN..." << endl;
	bank.printBankAccountsInfo(egn2);



	// DON'T FORGET TO DELETE ANY DYNAMICALLY ALLOCATED MEMORY:
	delete[] employees; 
	delete[] bankAccounts;
	return 0;
}
