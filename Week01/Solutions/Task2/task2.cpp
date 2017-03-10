#include <iostream>
#include <cstring>
using namespace std;

const int SIZE = 100;
const int EGN_SIZE = 10;

const int currentYear = 17; // 2017

enum Gender
{
    MALE,
    FEMALE
};

enum FamilyStatus
{
    SINGLE,
    ENGAGED,
    MARRIED,
    DIVORSED,
    WIDOWED
};

struct Person
{
    char firstName[SIZE];
    char middleName[SIZE];
    char lastName[SIZE];
    int EGN[EGN_SIZE];
    Gender gender;
    FamilyStatus familyStatus;
    bool isStudying;
    bool isWorking;
};

void initPerson(Person& person, char* firstName, char* middleName, char* lastName, int* EGN, Gender gender, FamilyStatus familyStatus, bool isStudying, bool isWorking)
{
    strcpy(person.firstName, firstName);
    strcpy(person.middleName, middleName);
    strcpy(person.lastName, lastName);

    for (int i = 0; i < EGN_SIZE; ++i) {
       person.EGN[i] = EGN[i];
    }

    person.gender = gender;
    person.familyStatus = familyStatus;
    person.isStudying = isStudying;
    person.isWorking = isWorking;
}

// a) function, which prints information about the person
void printPerson(Person person)
{
    cout << "Person info:" << endl;
    cout << "\tFirst name: " << person.firstName << endl;
    cout << "\tMiddle name: " << person.middleName << endl;
    cout << "\tLast name: " << person.lastName << endl;
    cout << "\tEGN: ";
    for (int i = 0; i < EGN_SIZE; ++i) {
       cout << person.EGN[i];
    }
    cout << endl;
    cout << "\tGender: " << person.gender << endl;
    cout << "\tFamily status: " << person.familyStatus << endl;
    cout << "\tIs studying: " << person.isStudying << endl;
    cout << "\tIs working: " << person.isWorking << endl;
}

// b) function, which returns the age of a person(we assume that nobody is more than 100 years old ;) )
int getPersonAge(Person person)
{
    short firstDigit = person.EGN[0];
    short secondDigit = person.EGN[1];

    int personYear = -1;
    personYear = firstDigit * 10 + secondDigit;
    if(firstDigit <= 1 && secondDigit <= 7) // the case when someone is born after 2000
    {
        return currentYear - personYear;
    } else
    {
        return currentYear + (100 - personYear);
    }
}

// c) function, which determines if two person objects are siblings or not
bool areSiblings(Person person1, Person person2)
{
   return (strcmp(person1.middleName, person2.middleName) == 0) && (strcmp(person1.lastName, person2.lastName) == 0);
}

// d) function, which determines if two person objects are married or not
bool areMarried(Person person1, Person person2)
{
    return (person1.familyStatus == MARRIED && person2.familyStatus == MARRIED) && (strcmp(person1.lastName, person2.lastName) == 0);
}

// e) function, which returns the number of people from a person array, who are neither studying nor working
int getNonStudyingAndWorkingCount(Person* people, int size)
{
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if((!people[i].isStudying) && (!people[i].isWorking))
        {
           count++;
        }
    }
    return count;
}

// f) function, which returns the number of people from a person array, who are students
int getStudentsCount(Person* people, int size)
{
    int count = 0;
    int age = -1;
    for (int i = 0; i < size; ++i)
    {
        if(people[i].isStudying)
        {
            age = getPersonAge(people[i]);
            if(age >= 6 && age <= 19)
            {
                count++;
            }
        }
    }

    return count;
}

// g) function, which returns the number of brother/sisters from a person array
int getSiblingsCount(Person* people, int size)
{
    int count = 0;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if(i == j)  // no point in comparing ourselves
            {
                continue;
            }

            if(areSiblings(people[i], people[j]))
            {
                count++;
            }
        }
    }

    return count / 2; // division by two because we count each set of siblings twice
}


int main()
{
    // Program demonstration:
    Person p;
    int egn[] = {9, 3, 0, 2, 1, 2, 5, 4, 9, 1};
    initPerson(p, "Stoyan", "Ivanov", "Ivanov", egn, MALE, MARRIED, true, true);
    printPerson(p);
    cout << p.firstName << "'s age: " << getPersonAge(p) << endl;
    cout << endl;

    const int SIZE = 2;
    Person people[SIZE];
    int egn1[] = {7, 8, 1, 2, 2, 2, 7, 4, 2, 8};
    int egn2[] = {7, 9, 0, 5, 1, 2, 5, 4, 9, 3};
    initPerson(people[0], "Peter", "Petrov", "Petrov", egn1, MALE, ENGAGED, true, false);
    initPerson(people[1], "Sara", "Petrov", "Petrov", egn2, FEMALE, ENGAGED, true, false);

    printPerson(people[0]);
    cout << endl;
    printPerson(people[1]);
    cout << endl;

    cout << "Age: " << getPersonAge(people[0]) << endl;
    cout << "Age: " << getPersonAge(people[1]) << endl;
    cout << endl;

    cout << "Are siblings: " << areSiblings(people[0], people[1]) << endl;
    cout << "Siblings count: " << getSiblingsCount(people, SIZE);

    return 0;
}