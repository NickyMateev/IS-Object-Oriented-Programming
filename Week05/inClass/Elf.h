#pragma once
#include <iostream>
#include <cstring>
using namespace std;


class Elf
{
private:
	char* name;
	size_t age;
	int ability;
	void copy(const Elf& other);
	void destroy();
public:
	Elf();
	Elf(const Elf& other);
	Elf& operator=(const Elf& other);
	~Elf();

	char* getName() const;
	size_t getAge() const;
	size_t getAbility() const;

	void setName(char* name);
	void setAge(size_t age);
	void setAbility(size_t ability);

	bool operator<(const Elf& rl);
	bool operator==(const Elf& elf);

	friend ostream& operator<<(ostream& os, const Elf& elf);
};
