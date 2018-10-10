// ConsoleApplication15.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "cassert"
using namespace std;

class Parent {
private:
	char* name;
	void copy(const Parent& other) {
		this->name = new char[strlen(other.name) + 1];
		strcpy(this->name, other.name);
	}
	void destroy() {
		delete[] name;
	}
public:
	Parent() {
		name = NULL;
	}
	Parent(const char* name) {
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}

	Parent(const Parent& other) {
		copy(other);
	}

	Parent& operator=(const Parent& other) {
		if (this != &other) {
			destroy();
			copy(other);
		}
		return *this;
	}

	virtual ~Parent() {
		destroy();
	}

};

class Child : Parent {
private:
	char* egn;
	void copy(const Child& other) {
		this->egn = new char[strlen(other.egn) + 1];
		strcpy(this->egn, other.egn);
	}
	void destroy() {
		delete[] egn;
	}
public:
	Child() {
		this->egn = NULL;
	}

	Child(const char* name, const char* egn) : Parent(name) {
		this->egn = new char[strlen(egn) + 1];
		strcpy(this->egn, egn);
	}

	Child(const Child& other) : Parent(other) {
		copy(other);
	}

	Child& operator=(const Child& other) {
		if (this != &other) {
			Parent::operator=(other);
			destroy();
			copy(other);
		}
		return *this;
	}

	~Child() {
		destroy();
	}

};

int main()
{
	
    return 0;
}

