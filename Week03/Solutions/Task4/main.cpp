#include <iostream>
#include <fstream>
using namespace std;

const int BUFFER_CAPACITY = 100;
const int INITIAL_CAP = 16;

void resizeArray(char*& array, int& capacity) {
    char* newArray =  new char[capacity * 2];
    for (int i = 0; i < capacity; i++) {
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
    capacity *= 2;
}

void appendCharacters(char*& originalText, int& arrLength, int& capacity, const char* textToAppend) {
    int i = 0;
    while(textToAppend[i]) {
        if (arrLength == capacity) {
            resizeArray(originalText, capacity);
        }
        originalText[arrLength++] = textToAppend[i++];
    }
}

char* readFileContent(const char* filePath) {
    char* fileContent = NULL;
        
    ifstream inputFileStream(filePath, ios::in);
    if (inputFileStream.is_open()) {
        int arrLength = 0;
        int arrCapacity = INITIAL_CAP;
        fileContent = new char[arrCapacity];
        char* buffer = NULL;
        while(!inputFileStream.eof()) {
            buffer = new char[BUFFER_CAPACITY];
            inputFileStream.getline(buffer, BUFFER_CAPACITY);
            appendCharacters(fileContent, arrLength, arrCapacity, buffer);
            delete[] buffer;
        }
        inputFileStream.close();
    }
    return  fileContent;
}

int calculateSentences(char* text) {
    int counter = 0;
    int i = 0;
    while(text[i]) {
        if(text[i] == '.' || text[i] == '?' || text[i] == '!') {
            counter++;
        }
        i++;
    }
    return counter;
}

int main() {
    const char* filePath = "text.txt";
    char* fileContent = readFileContent(filePath);
    cout << "Total sentences: " << calculateSentences(fileContent) << endl;

    delete[] fileContent;
    return 0;
}