#pragma once
#include "Elf.h"
#include <iostream>

class ElfTeam
{
private:
	char* name;
	Elf* elfs;
	size_t count;
	size_t capacity;

	void copy(const ElfTeam& team);
	void destroy();
	void resize();
	bool contains(Elf elf);
public:
	ElfTeam();
	ElfTeam(const ElfTeam& team);
	ElfTeam& operator= (const ElfTeam& team);
	~ElfTeam();

	bool addElf(Elf elf);
	size_t getStrength() const;

	bool operator<(const ElfTeam& rl);
	ElfTeam& operator+(const ElfTeam& rl);
	ElfTeam& operator+=(const ElfTeam& rl);

	ElfTeam& operator*(const ElfTeam& rl);
	ElfTeam& operator*=(const ElfTeam& rl);

	friend ostream& operator<<(ostream& os, const ElfTeam& team);
};


