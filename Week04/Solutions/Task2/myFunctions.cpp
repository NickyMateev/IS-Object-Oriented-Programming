//
// Created by nickym on 3/15/17.
//

#include "myFunctions.h"

int mystrlen(const char* str)
{
    int length = 0;
    while (str[length])
    {
        length++;
    }
    return length;
}

void mystrcpy(char*& dest, const char* src)
{
    int size = mystrlen(src) + 1;
    dest = new char[size];
    strcpy(dest, src);
}

