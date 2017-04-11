//
// Created by Mateev, Nikolay on 4/11/17.
//

#include "myFunctions.h"

int mystrlen(const char* word)
{
    if(word != NULL){
        int length = 0;
        while(word[length] != '\0')
            length++;
        return length;
    }

    return 0;
}

void mystrcpy(char*& destination, const char* source)
{
    if(source != NULL) {
        size_t sourceLength = mystrlen(source);

        destination = new char[sourceLength + 1];
        for(int i = 0; i <= sourceLength; i++)
            destination[i] = source[i];
    }
}