#include <iostream>
using namespace std;

int mystrlen(const char* str) {
    int i = -1;
    while(str[++i]);
    return i;
}

void mystrcpy(char*& destination, const char* source) {
    delete[] destination; // deleting in case the pointer was referring to some dynamic array 

    int length = mystrlen(source);
    destination = new char[length + 1]; // it's + 1, because we want to copy the '\0' symbol as well
    for (int i = 0; i <= length; i++) {
        destination[i] = source[i];
    }
}

int main() {
    const char* src = "Nicky";
    char* dest = NULL;
    mystrcpy(dest, src);
    cout << "Source: " << src << endl;
    cout << "Destination: " << dest << endl;

    return 0;
}