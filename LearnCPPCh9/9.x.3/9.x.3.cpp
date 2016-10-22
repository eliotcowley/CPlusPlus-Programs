/* 
	9.x.3.cpp : Write your own integer array class named IntArray from scratch (do not use std::array or std::vector). Users should pass in the size of
	the array when it is created, and the array should be dynamically allocated. Use assert statements to guard against bad data. Create any
	constructors or overloaded operators needed to make the following program operate correctly.

	This program should print:

	5 8 2 3 6
	5 8 2 3 6
*/

#include "stdafx.h"
#include <iostream>
#include <cassert>
using namespace std;

class IntArray
{
private:
	int m_size;
	int* m_array;

public:
	IntArray(const int size);
	IntArray(const IntArray &intArray);
	~IntArray();
	int& operator[](const int index);
	friend ostream& operator<<(ostream &out, const IntArray &intArray);
	IntArray& operator=(const IntArray &intArray);
};

IntArray::IntArray(const int size)
	: m_size {size}
{
	assert((size > 0) && ("IntArray size should be a positive integer"));
	m_array = new int[m_size] {0};
}

IntArray::IntArray(const IntArray & intArray):
	m_size {intArray.m_size}
{
	m_array = new int[m_size] {0};
	for (int i{ 0 }; i < m_size; i++)
	{
		m_array[i] = intArray.m_array[i];
	}
}

IntArray::~IntArray()
{
	delete[] m_array;
}

int & IntArray::operator[](const int index)
{
	assert(index >= 0);
	assert(index < m_size);
	return m_array[index];
}

IntArray & IntArray::operator=(const IntArray & intArray)
{
	// self-assignment guard
	if (this == &intArray)
		return *this;

	// If this array already exists, delete it so we don't leak memory
	delete[] m_array;

	m_size = intArray.m_size;

	// Allocate a new array
	m_array = new int[m_size];

	// Copy elements from original array to new array
	for (int count{ 0 }; count < intArray.m_size; ++count)
		m_array[count] = intArray.m_array[count];

	return *this;
}

ostream & operator<<(ostream &out, const IntArray &intArray)
{
	for (int i{ 0 }; i < intArray.m_size; i++)
	{
		out << intArray.m_array[i] << ' ';
	}
	return out;
}

IntArray fillArray()
{
	IntArray a(5);
	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

int main()
{
	IntArray a = fillArray();
	std::cout << a << '\n';

	IntArray b(1);
	a = a;
	b = a;

	std::cout << b << '\n';

	return 0;
}