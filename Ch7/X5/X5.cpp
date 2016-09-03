/* 
	X5.cpp : Given two int*s pointing into an array, find and output the number of ints between the two pointed-to ints
	(zero if they point to the same element).
*/

#include "stdafx.h"
#include<iostream>

using namespace std;

int getNumIntsBetweenTwoIntsInArray(int intArray[], int* first, int* second)
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
	int intArray[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int* first{ intArray };
	int* second{ &intArray[5] };
	int count{ getNumIntsBetweenTwoIntsInArray(intArray, first, second) };

	cout << count << '\n';

	return 0;
}

