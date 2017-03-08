#include <iostream>

using namespace std;

int main() {
    int count;
    cout << "Enter count:"<< endl;
    cin >> count; // 5;
    // dynamically allocating a one dimensional array:
    int* arr = new int[count];


    // dynamically
    int rows = 5;
    int cols = 6;

    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
       matrix[i] = new int[cols];
    }


    // deleting a two dimensional array:
    for (int j = 0; j < rows; ++j) {
       delete[] matrix[j];
    }
    delete[] matrix;

    // deleting a one dimensional array:
    delete[] arr;
    return 0;
}