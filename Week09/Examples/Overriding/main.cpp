#include <iostream>
#include "B.h"
using namespace std;


int main() {
    int x = 5;
    int y = 6;

    A a(x);
    B b(y);

    cout << a.getSomeNumber() << endl; // expected: 5
    cout << b.getSomeNumber() << endl; // expected: 12

    return 0;
}