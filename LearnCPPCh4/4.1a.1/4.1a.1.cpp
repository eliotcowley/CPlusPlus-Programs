/* 
	4.1a.1.cpp : Write a program that asks the user to enter two integers, the second larger than the first. If the user
	entered a smaller integer for the second integer, use a block and a temporary variable to swap the smaller and larger
	values. Then print the value of the smaller and larger variables. Add comments to your code indicating where each
	variable dies.

	The program output should match the following:
	
	Enter an integer: 4
	Enter a larger integer: 2
	Swapping the values
	The smaller value is 2
	The larger value is 4
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int smaller, larger;

	cout << "Enter an integer: ";
	cin >> smaller;

	cout << "Enter a larger integer: ";
	cin >> larger;

	if (smaller > larger)
	{
		cout << "Swapping the values...\n";
		int temp{ smaller };
		smaller = larger;
		larger = temp;
	} // temp dies

	else if (smaller == larger)
	{
		cout << "The values are equal.\n";
		return 0;
	}

	cout << "The smaller value is " << smaller << '\n';
	cout << "The larger value is " << larger << '\n';

    return 0;
} // smaller, larger die

