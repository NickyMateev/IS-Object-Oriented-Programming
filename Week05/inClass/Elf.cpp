#include "Elf.h"

void Elf::copy(const Elf& other)
{
	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);

	this->age = other.age;
	this->ability = other.ability;
}
void Elf::destroy()
{
	delete[] this->name;
}

Elf::Elf()
{
	this->name = new char[1];
	this->name[0] = '\0';
	this->age = 0;
	this->ability = 0;
}
Elf::Elf(const Elf& other)
{
	copy(other);
}
Elf& Elf::operator=(const Elf& other)
{
	if (this != &other)
	{
		destroy();
		copy(other);
	}
	return *this;
}
Elf::~Elf()
{
	destroy();
}

char* Elf::getName() const
{
	return this->name;
}
size_t Elf::getAge() const
{
	return this->age;
}
size_t Elf::getAbility() const
{
	return this->ability;
}

void Elf::setName(char* name)
{
	delete[] this->name;

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void Elf::setAge(size_t age)
{
	if (age > 300) return;
	this->age = age;
}
void Elf::setAbility(size_t ability)
{
	if (ability > 15) return;
	this->ability = ability;
}

bool Elf::operator<(const Elf& rl)
{
	return this->ability < rl.ability && this->age > rl.age;
}
bool Elf::operator==(const Elf& elf)
{
	return !strcmp(this->name, elf.name) &&
		this->ability == elf.ability && this->age == elf.age;
}

ostream& operator<<(ostream& os, const Elf& elf)
{
	os << elf.name << "\n" << elf.age << "\n" << elf.ability;
	return os;
}

