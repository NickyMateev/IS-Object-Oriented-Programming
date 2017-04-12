#include <iostream>
#include "Vector.h"

int main() {

    Vector vector;
    vector.add(5);
    vector.add(1);
    vector.add(6);
    vector.add(2);
    vector.add(4);
    vector.add(10);
    cout << vector << endl;

    cin >> vector;
    cout << vector << endl;

    cout << "Second element: " << vector[1] << endl;

    return 0;
}