#include "stdafx.h"
#include "myFunctions.h"

int mystrlen(char* str)
{
	int length = 0;
	while (str[length])
	{
		length++;
	}
	return length;
}

void mystrcpy(char*& dest, char* src)
{
	int size = mystrlen(src) + 1;
	dest = new char[size];
	strcpy_s(dest, size, src);
}