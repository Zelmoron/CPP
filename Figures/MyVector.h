#pragma once
#include <string.h>
#include <iostream>
using namespace std;
template<class T>
class MyVector {
public:
	MyVector(int n);
	MyVector();
	void push_back(T elem);
	void pop_back();
	void erase(int index);
	int size();
	T& operator[](int index);
	T back();
	~MyVector();
private:
	T* data;
	int len;
};

template<class T>
inline MyVector<T>::MyVector(int n)
{
	data = new T[n];
	len = n;
}

template<class T>
inline MyVector<T>::MyVector() : MyVector(0) {}


template<class T>
inline void MyVector<T>::push_back(T elem)
{
	T* old_data = data;
	data = new T[len + 1];

	for (int i = 0; i < len; i++)
		data[i] = old_data[i];

	data[len] = elem;

	len += 1;
	delete[] old_data;
}

template<class T>
inline void MyVector<T>::pop_back()
{
	T* old_data = data;
	data = new T[len - 1];

	for (int i = 0; i < len - 1; i++)
		data[i] = old_data[i];

	len -= 1;
	delete[] old_data;
}

template<class T>
inline void MyVector<T>::erase(int index)
{
	T* old_data = data;
	data = new T[len - 1];

	for (int i = 0; i < len; i++) {
		if (i == index)
			continue;
		if (i < index)
			data[i] = old_data[i];
		else
			data[i - 1] = old_data[i];
	}

	len -= 1;
	delete[] old_data;
}

template<class T>
inline int MyVector<T>::size()
{
	return len;
}

template<class T>
inline T& MyVector<T>::operator[](int index)
{
	return data[index];
}

template<class T>
inline T MyVector<T>::back()
{
	return operator[](len - 1);
}

template<class T>
inline MyVector<T>::~MyVector()
{
	delete[] data;
}
