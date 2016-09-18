/* 
	4.2.cpp : Rewrite the selection sort code above to sort in descending order (largest numbers first). Although this may
	seem complex, it is actually surprisingly simple.
*/

#include "stdafx.h"
#include <utility> // for std::swap, use <utility> instead if C++11
#include <iostream>

int main()
{
	const int length = 5;
	int array[length] = { 30, 50, 20, 10, 40 };

	// Step through each element of the array
	for (int startIndex = 0; startIndex < length; ++startIndex)
	{
		// largestIndex is the index of the smallest element we've encountered so far.
		int largestIndex = startIndex;

		// Look for largest element remaining in the array (starting at startIndex+1)
		for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
		{
			// If the current element is larger than our previously found largest
			if (array[currentIndex] > array[largestIndex])
				// This is the new largest number for this iteration
				largestIndex = currentIndex;
		}

		// Swap our start element with our largest element
		std::swap(array[startIndex], array[largestIndex]);
	}

	// Now print our sorted array as proof it works
	for (int index = 0; index < length; ++index)
		std::cout << array[index] << ' ';

	return 0;
}

