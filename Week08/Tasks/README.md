# Week 08 - Tasks

## Task 1 - Creature hierarchy

Да се създаде клас **Creature**, който съдържа в себе си име на създание, живот, защита и атака. Също така трябва да се създадат класовете **Orc** и **Elf**, които *наследяват* класа **Creature** и добавят следната функционалност.

За класа **Orc**:
 * трябва да се добави поле сила, което ще добавя бонус атака и живот на орка
 
За класа **Elf**:
 * трябва да се реализира метод за специален ефект върху атаката или защитата на елф

За всеки един от класовете трябва да се реализира голяма 4-ка( ако е нужно). Да се реализират операторите за изход и за сравнение.


## Task 2 - Mammal kingdom

Да се създаде клас **Mammal**, който съдържа в себе си години(age), брой на краката(numberOfLegs) и дали бозайникът има козина(fur).
Mamal класът притежава следният интерфейс:

* virtual char* getSpeciesName() const; //returns the name of the class
* virtual bool eats(Food food) const; //Food is an enum
* virtual Color furColor() const; //Color is an enum
* virtual bool canJump() const;
* virtual bool canSwim() const;
* virtual bool isSameSpeciesLike(Mammal* otherMammal);
	
Също така да се реализират класове **Hippo**, **Dog**, **Kangaroo**, **Human**, които наследяват **Mammal**.
