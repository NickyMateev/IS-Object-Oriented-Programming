#include <iostream>
#include <fstream>

using namespace std;

// Task 1 2 3 4
struct Student
{
    char name[100];
    int age;
    int FN;
    Student(){}
};

void write(char* pathToFile, Student t)
{
    ofstream outputFile;
    outputFile.open(pathToFile, ios::out | ios::app);
    outputFile << t.name << endl;
    outputFile << t.age << endl;
    outputFile << t.FN<< endl;
    outputFile.close();
}

Student read(char*  pathToFile)
{
    ifstream inputFile;
    inputFile.open(pathToFile, ios::in);
    Student t;
    inputFile.getline(t.name, 100);
    inputFile >> t.age;
    inputFile >> t.FN;
    inputFile.ignore();
    inputFile.close();
    return t;
}

void writeAllStudents(char* pathToFile, Student students[], size_t size)
{
    ofstream outFile;
    outFile.open(pathToFile, ios::out);

    outFile << size << endl;

    for(size_t i = 0; i < size; ++i)
    {
        outFile << students[i].name << endl;
        outFile << students[i].age << endl;
        outFile << students[i].FN << endl;
    }
    outFile.close();
}

void readAllStudents(char* pathToFile)
{
    ifstream inputFile;
    inputFile.open(pathToFile, ios::in);
    size_t size;
    inputFile >> size;
    cout << size;
    inputFile.ignore();
    Student students[size];
    for(size_t i = 0 ; i < size; ++i)
    {
        inputFile.getline(students[i].name, 100);
        inputFile >> students[i].age;
        inputFile >> students[i].FN;
        inputFile.ignore();
    }
    writeAllStudents("test.txt", students, size);

    for(int i = 0; i <size; ++i)
    {
        cout << students[i].name;
    }
    inputFile.close();
}



//Task 5 6 7 8
class Animal
{
public:
    char name[100];
    int age;
    char type[30];
    Animal(){}

    void write(char* pathToFile)
    {
        ofstream outFile;
        outFile.open(pathToFile, ios::out);
        outFile << this -> name;
        outFile << this ->age;
        outFile << this -> type;
        outFile.close();
    }

    void read(char* pathToFile)
    {
        ifstream inputFile;
        inputFile.open(pathToFile, ios::in);
        inputFile.getline(this -> name, 100);
        inputFile >> this -> age;
        inputFile.ignore();
        inputFile.getline(this -> type, 30);
        inputFile.close();
    }
};

void writeAnimals(char* pathToFile, Animal animals[], size_t size)
{
    ofstream outFile;
    outFile.open(pathToFile, ios::out);
    outFile << size << endl;
    for(size_t i = 0; i < size; ++i)
    {
        outFile << animals[i].name << endl;
        outFile << animals[i].age << endl;
        outFile << animals[i].type << endl;
    }
    outFile.close();
}

void readAnimals(char* pathToFile)
{
    ifstream inputFile;
    inputFile.open(pathToFile, ios::in);

    size_t size;
    inputFile >> size;
    Animal animals[size];

    for(size_t i = 0; i < size; ++i)
    {
        inputFile.getline(animals[i].name, 100);
    }
}

class Mamal
{
public:
    char type[30];
    int hight;
    int weight;
    bool hasFur;
    Mamal(){};
};

//task 9
Mamal findHeaviestMamal(Mamal* mamals, size_t size)
{
    Mamal heaviest = mamals[0];

    for(size_t i = 0; i < size; ++i)
    {
        if(heaviest.weight < mamals[i].weight)
        {
            heaviest = mamals[i];
        }
    }
    return heaviest;
}
//task 9
Mamal findMamalByHight(Mamal* mamals, size_t size)
{
    Mamal maxMamal = mamals[0];

    for(size_t i = 0; i < size; ++i)
    {
        if(maxMamal.hight < mamals[i].hight)
        {
            maxMamal = mamals[i];
        }
    }
    return maxMamal;
}
//task 10
Mamal* mamalsWithoutFur(Mamal* mamals, size_t size)
{
    Mamal result[size];
    size_t counter = 0;

    for(size_t i=0; i < size; ++i)
    {
        if(mamals[i].hasFur)
        {
            result[counter] = mamals[i];
        }
    }
    return result;
}
int main()
{

    return 0;
}
