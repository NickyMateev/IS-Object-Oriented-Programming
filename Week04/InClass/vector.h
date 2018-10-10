#pragma once
const int INIT_SIZE = 4;

template<class T>
class Vector
{
private:
	T* data;
	int capacity;
	int used;

	void resize();
	void copy(const T&);
	void destroy();

public:
	Vector();
	Vector(T*, int);
	Vector(const Vector&);
	Vector& operator=(const Vector&);
	~Vector();

	T get(int) const;
	void set(int);

	bool contains(T) const;
	bool remove(T);
	bool removeAt(T, int);
};


template<typename T>
Vector<T>::Vector() {
	this->data = new T[INIT_SIZE];
	this->used = 0;
	this->capacity = INIT_SIZE;
}

template<typename T>
Vector<T>::Vector(T* elements, int size)
{
	this->data = new T[size * 2];
	for (size_t i = 0; i < size; i++)
	{
		this->data[i] = elements[i];
	}
	this->used = size;
	this->capacity = size * 2;
}

template<typename T>
Vector<T>::~Vector()
{
	delete[] this->data;
}

template<typename T>
T Vector<T>::get(int index) const
{
	// validation logic...
	return data[index];
}