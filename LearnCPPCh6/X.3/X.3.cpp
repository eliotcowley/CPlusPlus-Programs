/* 
	X.3.cpp : Write your own function to swap the value of two integer variables. Write a main() function to test it.

	Hint: Use reference parameters
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

void swap(int &x, int &y)
{
	int temp{ x };
	x = y;
	y = temp;
}

int main()
{
	cout << "Enter a number: ";
	int x;
	cin >> x;
	cout << "Enter another number: ";
	int y;
	cin >> y;
	cout << "You entered " << x << " and " << y << ".\n";
	swap(x, y);
	cout << "After swapping, the values are " << x << " and " << y << ".\n";
    return 0;
}

