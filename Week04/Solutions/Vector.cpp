#pragma once
#include <iostream>

using namespace std;
template <typename T>
class Vector
{
    T* array;
    int current_size;
    int capacity;

    void remove()
    {

        delete[] array;
    }

    void copy(const Vector & other)
    {

        this->array = new T [other.capacity];
        for(int i=0; i<this->current_size; i++)
        {

            array[i]=other.array[i];
        }

        this->current_size=other.current_size;
        this->capacity=other.capacity;

    }
    void resize()
    {
        T * buffer = new T [2*this->capacity];
        for(int i=0; i<this->current_size; i++)

        {
            buffer[i]=this->array[i];

        }
        this->remove();
        this->array=buffer;
        this->capacity*=2;
    }
public:

    Vector()
    {
        this->array=NULL;
        this->current_size=0;
        this->capacity=0;
    }

    Vector (const Vector & other)
    {
        this->copy(other);

    }

    ~ Vector()
    {

        this->remove();
    }

    Vector & operator = (const Vector & other)
    {
        if(this == &other)
        {
            this->remove();
            this->copy(other);

        }
        return *this;
    }
    Vector (T* other, int size, int _capacity)
    {
        this->array=new T [_capacity];
        for(int i=0; i<size; i++)
        {
            this->array[i]=other[i];

        }
        this->current_size=size;
        this->capacity=_capacity;
    }

    void print()
    {
        for(int i=0; i<this->current_size; i++)
        {
            cout<<this->array[i]<<" ";


        }
        cout<<endl;
    }

    T  get(int index)
    {
        if(index > this -> current_size)
        {
            return T();
        }
        return this->array[index];


    }

    int& operator[](int x)
    {
        return  this->array[x];

    }

    const int& operator[](int x) const
    {
        return this->array[x];

    }

    void insert(int index, T element)
    {
        this->current_size++;
        if(current_size >= capacity)
        {
            resize();
        }

        for(int i = index; i < this->current_size; i++)
        {
            this -> array[i + 1] = this->array[i];
        }

        this ->array[index] = element;
    }

    bool contains (T element)
    {
        for(int i=0; i<this->current_size; i++)
        {

            if(this->array[i]==element)
            {

                return true;

            }
        }

        return false;
    }
    bool remove (T element)
    {
        bool res=false;
        for(int i=0; i<this->current_size; i++)
        {

            if(this->array[i]==element)
            {
                this->current_size--;
                res=true;
                for(int j=i; j<this->current_size; j++)
                {

                    array[i]=array[i+1];

                }


            }

        }


        return res;
    }

    void removeAt(size_t index)
    {
        if(index >= this ->capacity)
        {
            return;
        }
        this->current_size--;

        for(int j=index; j<this->current_size; j++)
        {

            array[j]=array[j+1];

        }
    }
};
int main()
{

    int vector1 [10];

    for(int i=0; i<2; i++)
    {
        cin>>vector1[i];

    }
    Vector<int> v1(vector1,2,5);
    v1.print();
    v1.print();
    cout<<v1.get(1)<<endl;
    cout<<v1[2]<<endl;
    v1[2]=62;
    cout<<v1[2]<<endl;
    v1.insert(2,6);
    v1.print();
    cout<<(v1.contains(7) ? "Contains": "Doesn't contains")<<endl;
    cout<< (v1.remove(7) ? "Removed":"Not removed")<<endl;
    v1.print();
    v1.removeAt(2);
    v1.print();

    return 0;
}
