#include "ElfTeam.h"




ElfTeam::ElfTeam()
{
	this -> elfs = NULL;
	this ->count = 0;
	this->capacity = 0;
}
ElfTeam::ElfTeam(const ElfTeam& team)
{
	copy(team);
}

ElfTeam& ElfTeam::operator= (const ElfTeam& team)
{
	if(this != &team)
	{
		destroy();
		copy(team);
	}
	return *this;
}

ElfTeam::~ElfTeam()
{
	destroy();
}


void ElfTeam::copy(const ElfTeam& team)
{
	this->elfs = new Elf[team.capacity];

	for(size_t i = 0; i < team.count; ++i)
	{
		this -> elfs[i] = team.elfs[i];
	}
	this -> capacity = team.capacity;
	this->count = team.count;
}

void ElfTeam::destroy()
{
	delete [] elfs;
}
ElfTeam& ElfTeam::operator+=(const ElfTeam& rl)
{
	for (size_t i = 0; i < rl.count; ++i)
	{
		this->addElf(rl.elfs[i]);
	}
	return *this;
}
bool ElfTeam::addElf(Elf elf)
{
	if (this->contains(elf))
	{
		return false;
	}

	if (count + 1 >= capacity)
	{
		resize();
	}

	this->elfs[count++] = elf;
	return true;
}

void ElfTeam::resize()
{
	Elf* temp = new Elf[this -> capacity * 2];
	for(size_t i = 0; i < capacity; ++i)
	{
		temp[i] = elfs[i];
	}

	delete [] this -> elfs;
	this -> elfs = temp;
	this -> capacity *=2;


}

bool ElfTeam::contains(Elf elf)
{
	for (size_t i = 0; i < this->count; ++i)
	{
		if (elf == this->elfs[i])
		{
			return true;
		}
	}
	return false;
}

size_t ElfTeam::getStrength() const
{
	size_t strengthCounter = 0 ;
	for(size_t i = 0; i < this -> capacity; ++i)
	{
		strengthCounter += this -> elfs[i].getAbility();
	}
}

bool ElfTeam::operator<(const ElfTeam& rl)
{
	return this ->getStrength() < rl.getStrength();
}

ElfTeam& ElfTeam::operator+(const ElfTeam& rl)
{
	ElfTeam newTeam(*this);
	return newTeam += rl;

}
ElfTeam& ElfTeam::operator*(const ElfTeam& rl)
{
	ElfTeam team;
	for(size_t i = 0; i < this ->count; ++i)
	{
		for(size_t j = 0; j < rl.count; ++j)
		{
			if(this ->elfs[i] == rl.elfs[i])
			{
				team.addElf(elfs[i]);
				break;
			}
		}
		
	}
	return team;
}


ostream& operator<<(ostream& os, const ElfTeam& team)
{
	for (size_t i = 0; i < team.count; ++i)
	{
		os << team.elfs[i];
	}
	return os;
}

int main()
{
	Elf e1;
	e1.setName("Stoyan");
	e1.setAbility(2);
	e1.setAge(23);
	Elf e2;
	e2.setName("Niki");
	e2.setAbility(1);
	e2.setAge(21);

	ElfTeam  team;
	team.addElf(e1);
	team.addElf(e2);
	cout << team;

	return 0;
}