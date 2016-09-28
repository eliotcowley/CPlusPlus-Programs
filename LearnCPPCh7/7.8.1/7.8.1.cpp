/* 
	7.8.1.cpp : In this quiz, we’re going to write a version of our basic calculator using function pointers.

	Create a short program asking the user for two integer inputs and a mathematical operation (‘+’, ‘-‘, ‘*’, ‘/’).
	Ensure the user enters a valid operation.

	Write functions named add(), subtract(), multiply(), and divide(). These should take two integer parameters and return
	an integer.

	Create a typedef named arithmeticFcn for a pointer to a function that takes two integer parameters and returns an
	integer.

	Write a function named getArithmeticFunction() that takes an operator character and returns the appropriate function
	as a function pointer.

	Modify your main() function to call getArithmeticFunction(). Call the return value from that function with your inputs
	and print the result.
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

typedef int(*arithmeticFcn)(int, int);

int getInteger()
{
	int i;
	cout << "Enter an integer: ";
	cin >> i;
	return i;
}

char getOperation()
{
	char op;
	cout << "Enter an operation (+, -, *, or /): ";
	cin >> op;
	while (op != '+' && op != '-' && op != '*' && op != '/')
	{
		cout << "Sorry, I didn't recognize that operation. Please enter +, -, *, or /: ";
		cin >> op;
	}
	return op;
}

int add(int a, int b)
{
	return (a + b);
}

int subtract(int a, int b)
{
	return (a - b);
}

int multiply(int a, int b)
{
	return (a * b);
}

int divide(int a, int b)
{
	return (a / b);
}

arithmeticFcn getArithmeticFunction(char op)
{
	switch (op)
	{
	case '+':
		return add;

	case '-':
		return subtract;

	case '*':
		return multiply;

	case '/':
		return divide;

	default:
		cout << "ERROR: Operation not recognized.\n";
		return nullptr;
	}
}

int main()
{
	int a{ getInteger() };
	int b{ getInteger() };
	char op{ getOperation() };

	arithmeticFcn function{ getArithmeticFunction(op) };
	cout << a << ' ' << op << ' ' << b << " = " << function(a, b) << '\n';

    return 0;
}

