#include <iostream>
#include <cstring>
#include "vector.h"
using namespace std;

template<typename T>
void printElem(T element)
{
	cout << element <<endl;
}

template<class K>
void swapElements(K& elem1, K& elem2)
{
	K temp = elem1;
	elem1 = elem2;
	elem2 = temp;
}

template<typename T>
void print(T* elements, size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		cout << elements[i] << "    ";
	}
	cout << endl;
}



int main() {
	int arr[4] = { 1,2,3,4 };
	Vector<int> v(arr, 4);
	cout << v.get(2) << endl;

	return 0;
}