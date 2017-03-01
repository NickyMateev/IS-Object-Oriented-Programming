#include <iostream>
#include <cstring>
using namespace std;

const int SIZE = 10;

struct Point
{
  int x;
  int y;
};

class Person
{
  private:
    char name[SIZE];
    int age;
    Point point;

    void mystrcpy(char* src, char* dest);
  public:
    Person();
    Person(char* name, int age);

    char* getName();
    int getAge();
    Point getPoint();

    void setAge(int);
    void setName(char*);

    void setPoint(Point);
    void setPoint(int, int);

};


Person::Person(char* name, int age)
{
  setName(name);
  setAge(age);
}

void Person::mystrcpy(char* src, char* dest)
{
  int size = strlen(src);
  if(size > SIZE) {
    return;
  }

  for(int i = 0; src[i] != '\0'; i++)
  {
    dest[i] = src[i];
  }
  dest[size] = '\0';
}

char* Person::getName()
{
  return name;
}

int Person::getAge()
{
  return age;
}


void Person::setAge(int newAge)
{
  age = newAge;
}

void Person::setName(char* newName)
{
  mystrcpy(newName, this->name);
}

int main()
{
  Person people[10];

  return 0;
}
