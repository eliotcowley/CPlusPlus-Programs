/* 
	7.11.2.cpp : Write a recursive function that takes an integer as input and returns the sum of all the numbers in the
	integer (e.g. 357 = 15). Print the answer for input 93427 (which is 25).
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

int sumDigits(int i)
{
	int sum;

	// Base case (i <= 9)
	if (i <= 9)
	{
		sum = i;
	}
	// Recursive case (i >= 10)
	else
	{
		sum = (i % 10) + sumDigits(i / 10);
	}

	return sum;
}

int main()
{
	int answer{ sumDigits(93427) };
	cout << "sumDigits(93427) = " << answer << '\n';
	if (answer == 25)
	{
		cout << "We got it!\n";
	}
	else
	{
		cout << "WRONG. - Donald Trump\n";
	}
    return 0;
}

