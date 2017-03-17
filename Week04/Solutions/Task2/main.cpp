#include <iostream>
#include "Animal.h"

int main() {
    // Program demonstration:

    Animal animal(10, 2, 3, 4, "Ivancho");
    animal.needs();
    cout << endl;
    cout << endl;
    animal.setCurrentFood(1);
    animal.setCurrentWater(5);
    animal.description();

    return 0;
}