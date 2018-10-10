#include <iostream>
using namespace std;
const int SIZE = 100;

/**
 *  This program creates a dynamic array
 *  with an initial capacity of 2.
 *  Using a for loop we'll be inserting
 *  20 values. The program will recognize each time 
 *  when the array is filled up and will resize it accordingly.
 **/

void resizeArr(int*& arr, int& capacity) {
	int* arr2 = new int[capacity * 2]; // dynamically allocating memory

	for (int i = 0; i < capacity; i++) { // copying the old values in the new array
		arr2[i] = arr[i];
	}
	capacity *= 2; // resizing the capacity
	delete[] arr; // deleting the old array

	arr = arr2; // redirecting the old pointer variable to point to the new array
}

int main()
{
	int capacity = 2;
	int size = 0;
	int* dynamicArr = new int[capacity];
	
	for (int i = 0; i < 20; i++) {
		if (size == capacity) {
			resizeArr(dynamicArr, capacity);			
		}
		dynamicArr[i] = i * 10;
		size++;
	}

    return 0;
}