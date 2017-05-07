#include <iostream>
using namespace std;

class Main {
public:
    virtual void greet() {
       cout << "Main greeting"  << endl;
    }
};

class Child : public Main {
public:
    void greet() { // method overriding
        cout << "Child greeting"  << endl;
    }
};

class AnotherChild : public Main {
public:
    void greet() {
        cout << "Another child greeting" << endl;
    }
};

int main() {
    cout << "Using objects:"  << endl;
    Main m;
    m.greet();

    Child c;
    c.greet();

    cout << endl;
    cout << "Using pointers: " << endl;
    Main* mPtr = &m;
    mPtr->greet();

    Child* cPtr = &c;
    cPtr->greet();

    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    cout << "Main pointer to Child object:" << endl;
    Child c2;

    Main* mPtrChild = &c2;
    mPtrChild->greet(); // polymorphism

    cout << endl;
    cout << endl;
    cout << endl;

    AnotherChild anotherChild;
    Main* mAnother = &anotherChild;
    anotherChild.greet();
    mAnother->greet();


    return 0;
}