// X5.cpp : Write a function itoa(int i, char b[]) that creates a string representation of i in b and returns b.

#include "stdafx.h"
#include <iostream>

using namespace std;

char* itoa(int i, char b[])
{
	// Get to last slot of b
	int index{ 0 };
	while (b[index + 1])
	{
		index++;
	}

	while (i > 0)
	{
		// Get last digit of i and put in last slot of b
		b[index] = i % 10;

		// Get rid of last digit
		i /= 10;

		// Move to previous slot of b
		index--;
	}

	return b;
}

int main()
{
	char ca[3];
	char* out;
	out = itoa(123, ca);
	for (int i = 0; i < 3; i++)
	{
		cout << *out++;
	}
	cout << endl;

    return 0;
}

