// X4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int atoi(const char* ccp)
{
	// Point to last character
	int index{ 0 };
	while (*(ccp + 1))
	{
		ccp++;
		index++;
	}

	// Get value of each decimal place
	int value{ 0 };
	int decimalPlace{ 1 };

	while (index >= 0)
	{
		// Get value of currently pointed-to digit
		int digit{ 0 };
		switch (*ccp)
		{
		case '0':
			break;
		case '1':
			digit = 1;
			break;
		case '2':
			digit = 2;
			break;
		case '3':
			digit = 3;
			break;
		case '4':
			digit = 4;
			break;
		case '5':
			digit = 5;
			break;
		case '6':
			digit = 6;
			break;
		case '7':
			digit = 7;
			break;
		case '8':
			digit = 8;
			break;
		case '9':
			digit = 9;
			break;
		}

		value += (digit * decimalPlace);
		index--;
		decimalPlace *= 10;
		ccp--;
	}

	return value;
}

int main()
{
	cout << atoi("123") << endl;
	cout << atoi("0") << endl;
	cout << atoi("01") << endl;
    return 0;
}

