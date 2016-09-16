/* 
	5.3.1.cpp : Write a function called calculate() that takes two integers and a char representing one of the
	following mathematical operations: +, -, *, /, or % (modulus). Use a switch statement to perform the appropriate
	mathematical operation on the integers, and return the result. If an invalid operator is passed into the function,
	the function should print an error. For the division operator, do an integer division.
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

int calculate(int a, int b, char c)
{
	switch (c)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		return a / b;
	case '%':
		return a % b;
	default:
		cerr << "ERROR: Operator not recognized\n";
		exit(1);
	}
}

int main()
{
	int a, b;
	char c;

	cout << "Enter an integer: ";
	cin >> a;
	cout << "Enter an operator: ";
	cin >> c;
	cout << "Enter another integer: ";
	cin >> b;
	cout << a << " " << c << " " << b << " = " << calculate(a, b, c) << '\n';
    return 0;
}

