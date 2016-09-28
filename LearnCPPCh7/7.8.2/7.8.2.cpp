/* 
	7.8.2.cpp : Now let’s modify the program we wrote in quiz 1 to move the logic out of the getArithmeticFcn and into an
	array.

	Create a struct named arithmeticStruct that has two members: a mathematical operator char, and an arithmeticFcn
	function pointer.

	Create a static global array of arithmeticStruct named arithmeticArray, initialized with each of the four arithmetic
	functions.

	Modify getArithmeticFcn to loop through the array and return the appropriate function pointer.
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

typedef int(*arithmeticFcn)(int, int);

struct arithmeticStruct
{
	char op;
	arithmeticFcn function;
};

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

arithmeticStruct arithmeticArray[]
{
	{ '+', add },
	{ '-', subtract },
	{ '*', multiply },
	{ '/', divide }
};

arithmeticFcn getArithmeticFunction(char op)
{
	for each (arithmeticStruct &var in arithmeticArray)
	{
		if (var.op == op)
		{
			return var.function;
		}
	}

	cout << "ERROR: Operation not recognized.\n";
	return nullptr;
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

