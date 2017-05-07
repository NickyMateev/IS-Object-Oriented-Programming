#include "B.h"

B::B(int num) : A(num){
}

int B::getSomeNumber() { // overriding the original behaviour from class A
    return this->num * 2;
}