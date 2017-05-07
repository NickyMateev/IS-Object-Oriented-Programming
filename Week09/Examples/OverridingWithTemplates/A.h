#ifndef EXAMPLE_A_H
#define EXAMPLE_A_H

template <typename T>
class A {
protected:
    T num;
public:
    A(T num);
    T getSomeNumber();
};

template <typename T>
A<T>::A(T num){
    this->num = num;
}

template <typename T>
T A<T>::getSomeNumber() {
    return this->num;
}

#endif //EXAMPLE_A_H
