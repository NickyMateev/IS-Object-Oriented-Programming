#include <iostream>
#include <fstream>
using namespace std;

void printArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        cout << "arr[" << i << "] = " << array[i] << endl;
    }
}

void resizeArray(int*& array, int& capacity) {
    int* newArray =  new int[capacity * 2];
    for (int i = 0; i < capacity; i++) {
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
    capacity *= 2;
}

int* retrieveNumbersFromFile(const char* filePath, int& count) {
    int* array = NULL;

    ifstream inputFileStream(filePath, ios::in);
    if (inputFileStream.is_open()) {
        int capacity = 2;
        array = new int[capacity];
        while(!inputFileStream.eof()) {
            if(count == capacity) {
                resizeArray(array, capacity);
            }
            inputFileStream >> array[count++];
        }

        inputFileStream.close();
    }
    
    return array;
}

int main() {
    const char* filePath = "numbers.txt";
    int count = 0;
    int* array  = retrieveNumbersFromFile(filePath, count);
    printArray(array, count);

    delete[] array;
    return 0;
}