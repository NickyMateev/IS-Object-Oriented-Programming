#include <iostream>
#include "B.h"
using namespace std;


int main() {
    int x = 5;
    double y = 6;

    A<int> a(x);
    B<double> b(y);

    cout << a.getSomeNumber() << endl; // expected: 5
    cout << b.getSomeNumber() << endl; // expected: 12

    return 0;
}