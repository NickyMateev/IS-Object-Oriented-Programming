#include "Smartphone.h"

int main() {
    Smartphone smartphone1("Smartphone 1", "Model 1", 299.99);
    Smartphone smartphone2("Smartphone 2", "Model 2", 449.99);

    cout << smartphone1 << endl << endl;
    cout << smartphone2 << endl << endl;

    Smartphone smartphone3;
    cout << "Enter info for Smartphone 3:" << endl;
    cin >> smartphone3;

    cout << "\n*** Smartphone created ***\n" << smartphone3 << endl;
    return 0;
}