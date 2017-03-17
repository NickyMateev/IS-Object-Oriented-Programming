#include <iostream>
#include "Employee.h"

int main() {
    // Program demonstration:

    Employee e1, e2(1, "Ivan", "Ivanov", 2000);
    cout << "E1 description: " << endl;
    e1.description();
    cout << endl;
    cout << "E2 description: " << endl;
    e2.description();
    cout << endl;

    Employee e3(e2);
    cout << "E3 description: " << endl;
    e3.raiseSalary(50);
    e3.description();
    cout << endl;

    return 0;
}