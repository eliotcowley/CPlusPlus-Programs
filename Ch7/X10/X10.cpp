/* 
	X10.cpp : Define an array of strings in which the strings contain the names of the months. Print those strings. Pass
	the array to a function that prints those strings.
*/

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

void printStringsInArray(string stringArray[], int size)
{
	for (int i {0}; i < size; i++)
	{
		cout << *stringArray << '\n';
		stringArray++;
	}
}

int main()
{
	string months[]{ "January", "February", "March", "April", "May", "June", "July", "August", "September", "October",
		"November", "December" };
	for (string s : months)
	{
		cout << s << '\n';
	}
	cout << '\n';
	printStringsInArray(months, 12);

    return 0;
}

