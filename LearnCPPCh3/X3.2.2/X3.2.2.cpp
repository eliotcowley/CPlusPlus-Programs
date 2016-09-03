/* 
	X3.2.2.cpp : Write a program that asks the user to input an integer, and tells the user whether the number is even or
	odd. Write a function called isEven() that returns true if an integer passed to it is even. Use the modulus operator
	to test whether the integer parameter is even. Hint: You’ll need to use if statements and the comparison operator (==)
	for this program. See section 2.7 -- Chars if you need a refresher on how to do this.
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

bool isEven(int i)
{
	return (i % 2) == 0;
}

int main()
{
	int i;
	cout << "Enter an integer: ";
	cin >> i;
	if (isEven(i))
	{
		cout << i << " is even!\n";
	}
	else
	{
		cout << i << " is odd!\n";
	}

    return 0;
}

