/* 
	X4.cpp : Given two char*s pointing into an array, find and output the number of characters between the two pointed-to
	characters (zero if they point to the same element).
*/

#include "stdafx.h"
#include<iostream>

using namespace std;

int getNumIntsBetweenTwoIntsInArray(char charArray[], char* first, char* second)
{
	int count{ 0 };

	while (first != second)
	{
		count++;
		first++;
	}

	return count;
}

int main()
{
	char charArray[]{ "Hello, world!" };
	char* first{ charArray };
	char* second{ &charArray[5] };
	int count{ getNumIntsBetweenTwoIntsInArray(charArray, first, second) };

	cout << count << '\n';

    return 0;
}

