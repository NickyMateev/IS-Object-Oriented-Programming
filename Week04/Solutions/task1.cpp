#include <iostream>

using namespace std;


template<typename T>
void printElem(T element)
{
	cout << element <<endl;
}

template<typename K>
int minElem(K* elements, size_t size)
{
    size_t minIndex = 0;
    for(size_t i = 0; i < size; ++i)
    {
        if(elements[minIndex] > elements[i])
        {
            minIndex = i;
        }
    }

    return minIndex;

}

template<typename T>
int mexElem(T* elements, size_t size)
{
    size_t maxElem = elements[0];
    for(size_t i = 0; i < size; ++i)
    {
        if(maxElem < elements[i])
        {
            maxElem = elements[i];
        }
    }

    return maxElem;

}

int main(){
    return 0; 
}