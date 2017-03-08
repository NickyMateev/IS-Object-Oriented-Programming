#include <iostream>
#include "Person.h"

using namespace std;

int main()
{
    char* firstName = "Stoyan";
    char* middleName = "Ivanov";
    char* lastName = "Ivanov";

    int egn = 123;
    Person people[10];
    char userInput[100];
    for (int i = 0; i < 10; ++i) {
        cout << "Person #" << i << ":"<<endl;
        cout << "First name: ";
        cin >> userInput; //stoyan
        people[i].setFirstName(userInput);
        cout << "Middle name: ";
        cin >> userInput; // ivanov
        people[i].setMiddleName(userInput);
        cout << "Last name: ";
        cin >> userInput; // ivanov
        people[i].setLastName(userInput);
    }

    Person p(firstName, middleName, lastName, egn);


    return 0;
}