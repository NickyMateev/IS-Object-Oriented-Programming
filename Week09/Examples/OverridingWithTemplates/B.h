#ifndef EXAMPLE_B_H
#define EXAMPLE_B_H
#include "A.h"

template <typename T>
class B : public A<T> {
public:
    B(T num);
    T getSomeNumber();
};


template <typename T>
B<T>::B(T num) : A<T>(num){
}

template <typename T>
T B<T>::getSomeNumber() {
    return this->num * 2;
}

#endif //EXAMPLE_B_H
