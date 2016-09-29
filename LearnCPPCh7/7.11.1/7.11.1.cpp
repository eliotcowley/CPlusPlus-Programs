/* 
	7.11.1.cpp : A factorial of an integer N (written N!) is defined as the product (multiplication) of all the numbers
	between 1 and N (0! = 1). Write a recursive function called factorial that returns the factorial of the input. Test it
	with the first 7 factorials.

	Hint: Remember that x * y = y * x, so the product of all the numbers between 1 and N is the same as the product of all
	the numbers between N and 1.
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

int factorial(int n)
{
	int output;

	// Base case (factorial(1) = 1, factorial(0) = 1)
	if (n <= 1)
	{
		output = 1;
	}
	// N! = N * (N-1)!
	else
	{
		output = n * factorial(n - 1);
	}
	return output;
}

int main()
{
	int n;
	cout << "Enter an integer: ";
	cin >> n;
	cout << n << "! = " << factorial(n) << '\n';
    return 0;
}

