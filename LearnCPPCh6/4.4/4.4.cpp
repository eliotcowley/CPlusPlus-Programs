/* 
	4.4.cpp : Add two optimizations to the bubble sort algorithm you wrote in the previous quiz question:
	Notice how with each iteration of bubble sort, the biggest number remaining gets bubbled to the end of the array.
	After the first iteration, the last array element is sorted. After the second iteration, the second to last array
	element is sorted too. And so on… With each iteration, we don’t need to recheck elements that we know are already
	sorted. Change your loop to not re-check elements that are already sorted.

	If we go through an entire iteration without doing a swap, then we know the array must already be sorted. Implement a
	check to determine whether any swaps were made this iteration, and if not, terminate the loop early. If the loop was
	terminated early, print on which iteration the sort ended early.

	Your output should match this:

	Early termination on iteration 6
	1 2 3 4 5 6 7 8 9
*/

#include "stdafx.h"
#include <iostream>
#include <utility>
using namespace std;

int main()
{
	int first{ 0 };
	int second{ 1 };
	const int length(9);
	int array[length] = { 6, 3, 2, 9, 7, 1, 5, 4, 8 };
	int swaps{ 0 };
	int last{ length };
	int iteration{ 1 };

	while (second < last)
	{
		if (array[first] > array[second])
		{
			swap(array[first], array[second]);
			swaps++;
		}
		first++;
		second++;
		if ((second >= last) && (swaps > 0))
		{
			first = 0;
			second = 1;
			swaps = 0;
			last--;
			iteration++;
		}
	}

	cout << "Early termination on iteration " << iteration << '\n';
	cout << "Sorted array: ";
	for (int i{ 0 }; i < length; i++)
	{
		cout << array[i] << " ";
	}
	cout << '\n';

    return 0;
}

