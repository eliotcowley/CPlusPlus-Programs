/* 
	4.3.cpp : This one is going to be difficult, so put your game face on.
	Another simple sort is called “bubble sort”. Bubble sort works by comparing adjacent pairs of elements, and swapping
	them if the criteria is met, so that elements “bubble” to the end of the array. Although there are quite a few ways to
	optimize bubble sort, in this quiz we’ll stick with the unoptimized version here because it’s simplest.
	Unoptimized bubble sort performs the following steps to sort an array from smallest to largest:
	A) Compare array element 0 with array element 1. If element 0 is larger, swap it with element 1.
	B) Now do the same for elements 1 and 2, and every subsequent pair of elements until you hit the end of the array. At
	this point, the last element in the array will be sorted.
	C) Repeat the first two steps again until the array is sorted.
	Write code that bubble sorts the following array according to the rules above:


	1
	2
	const int length(9);
	int array[length] = { 6, 3, 2, 9, 7, 1, 5, 4, 8 };

	Print the sorted array elements at the end of your program.
	Hint: If we’re able to sort one element per iteration, that means we’ll need to iterate as many times as there are
	numbers in our array to guarantee that the whole array is sorted.
	Hint: When comparing pairs of elements, be careful of your array’s range.
*/

#include "stdafx.h"
#include <utility>
#include <iostream>
using namespace std;

int main()
{
	int first{ 0 };
	int second{ 1 };
	const int length(9);
	int array[length] = { 6, 3, 2, 9, 7, 1, 5, 4, 8 };
	int swaps{ 0 };
	int iteration{ 1 };

	while (second < length)
	{
		if (array[first] > array[second])
		{
			swap(array[first], array[second]);
			swaps++;
		}
		first++;
		second++;
		if ((second >= length) && (swaps > 0))
		{
			first = 0;
			second = 1;
			swaps = 0;
			iteration++;
		}
	}

	cout << "Early termination on iteration " << iteration << '\n';
	cout << "Sorted array: ";
	for (int i{ 0 }; i < length; i++)
	{
		cout << array[i] << " ";
	}

    return 0;
}

