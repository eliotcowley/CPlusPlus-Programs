/* 
	8.3.3.cpp : Now let’s try something a little more complex. Let’s write a class that implements a simple stack from
	scratch. Review lesson 7.9 -- The stack and the heap if you need a refresher on a what a stack is.

	The class should be named Stack, and should contain:
	* A private fixed array of integers of length 10.
	* A private integer to keep track of the length of the stack.
	* A public member function named reset() that sets the length to 0 and all of the element values to 0.
	* A public member function named push() that pushes a value on the stack. push() should return false if the array is
	already full, and true otherwise.
	* A public member function named pop() that pops a value off the stack and returns it. If there are no values on the
	stack, it should assert out.
	* A public member function named print() that prints all the values in the stack.

	Make sure the following program executes correctly:

	int main()
	{
		Stack stack;
		stack.reset();
 
		stack.print();
 
		stack.push(5);
		stack.push(3);
		stack.push(8);
		stack.print();
 
		stack.pop();
		stack.print();
 
		stack.pop();
		stack.pop();
 
		stack.print();
 
		return 0;
	}

	This should print:

	( )
	( 5 3 8 )
	( 5 3 )
	( )
*/

#include "stdafx.h"
#include <cassert>
#include <iostream>
using namespace std;

class Stack
{
private:
	static const int m_max{ 10 };
	int m_array[m_max];
	int m_length;

public:
	void reset()
	{
		m_length = 0;
		for each (int i in m_array)
		{
			i = 0;
		}
	}

	bool push(int i)
	{
		if (m_length < m_max)
		{
			m_array[m_length] = i;
			m_length++;
			return true;
		}
		return false;
	}

	int pop()
	{
		assert(m_length > 0);
		m_length--;
		return m_array[m_length];
	}

	void print()
	{
		cout << "( ";

		for (int i{ 0 }; i < m_length; i++)
		{
			cout << m_array[i] << ' ';
		}

		cout << ")\n";
	}
};

int main()
{
	Stack stack;
	stack.reset();

	stack.print();

	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();

	stack.print();

    return 0;
}

