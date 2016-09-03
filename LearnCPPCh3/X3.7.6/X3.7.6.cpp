/* 
	X3.7.6.cpp : Write a program that asks the user to input a number between 0 and 255. Print this number as an 8-bit
	binary number (of the form #### ####). Don’t use any bitwise operators.

	Hint: Use method 2. Assume the largest power of 2 is 128.

	Hint: Write a function to test whether your input number is greater than some power of 2. If so, print ‘1’ and return
	your number minus the power of 2.
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

bool compareToPowerOf2(int num, int power)
{
	return (num >= pow(2, power));
}

int main()
{
	int num;
	int power{ 7 };
	cout << "Please enter a number between 0 and 255: ";
	cin >> num;

	while (power >= 0)
	{
		if (compareToPowerOf2(num, power))
		{
			cout << 1;
			num -= pow(2, power);
		}
		else
		{
			cout << 0;
		}

		if (power == 4)
		{
			cout << " ";
		}

		power--;
	}

	cout << '\n';

    return 0;
}

