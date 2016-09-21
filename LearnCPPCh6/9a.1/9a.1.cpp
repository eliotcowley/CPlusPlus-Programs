/* 
	9a.1.cpp : Write a program that:

	* Asks the user how many names they wish to enter.
	* Asks the user to enter each name.
	* Calls a function to sort the names (modify the selection sort code from lesson 6.4 -- Sorting an array using
	selection sort)
	* Prints the sorted list of names.

	Hint: Use a dynamic array of std::string to hold the names.
	Hint: std::string supports comparing strings via the comparison operators < and >

	Your output should match this:

	How many names would you like to enter? 5
	Enter name #1: Jason
	Enter name #2: Mark
	Enter name #3: Alex
	Enter name #4: Chris
	Enter name #5: John

	Here is your sorted list:
	Name #1: Alex
	Name #2: Chris
	Name #3: Jason
	Name #4: John
	Name #5: Mark
*/

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	// Determine length of array
	int length;
	cout << "How many names would you like to enter? ";
	cin >> length;

	// Determine names and add to array
	int i{ 1 };
	string *names = new string[length];
	while (i <= length)
	{
		string name;
		cout << "Enter name #" << i << ": ";
		cin >> name;
		names[i - 1] = name;
		i++;
	}

	// Sort array

	// Step through each element of the array
	for (int startIndex = 0; startIndex < length; ++startIndex)
	{
		// smallestIndex is the index of the smallest element we've encountered so far.
		int smallestIndex = startIndex;

		// Look for smallest element remaining in the array (starting at startIndex+1)
		for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
		{
			// If the current element is smaller than our previously found smallest
			if (names[currentIndex] < names[smallestIndex])
				// This is the new smallest number for this iteration
				smallestIndex = currentIndex;
		}

		// Swap our start element with our smallest element
		std::swap(names[startIndex], names[smallestIndex]);
	}

	cout << "Here is your sorted list:\n";

	// Now print our sorted array as proof it works
	for (int index = 0; index < length; ++index)
		std::cout << names[index] << ' ';

	cout << '\n';

    return 0;
}

