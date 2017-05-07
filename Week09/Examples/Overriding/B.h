#ifndef EXAMPLE_B_H
#define EXAMPLE_B_H
#include "A.h"

class B : public A {
public:
    B(int num);
    int getSomeNumber();
};

#endif //EXAMPLE_B_H
