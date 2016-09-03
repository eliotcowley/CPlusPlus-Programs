/* 
	X7.cpp : Write a function that swaps (exchanges the values of) two integers. Use int* as the argument type. Write
	another swap function using int& as the argument type.
*/

#include "stdafx.h"
#include<iostream>

using namespace std;

void swap(int* first, int* second)
{
	int temp{ *first };
	first = second;
	second = &temp;
}

void swap(int& first, int& second)
{
	int temp{ first };
	first = second;
	second = temp;
}

int main()
{
	int first, second;
	cout << "Enter a number to swap: ";
	cin >> first;
	cout << "Enter another number: ";
	cin >> second;
	cout << "You entered " << first << " and " << second << ".\n";
	cout << "Swapping as int* arguments...\n";
	swap(first, second);
	cout << "Now the numbers are " << first << " and " << second << ".\n\n";

	int third, fourth;
	cout << "Enter a number to swap: ";
	cin >> third;
	cout << "Enter another number: ";
	cin >> fourth;
	cout << "You entered " << third << " and " << fourth << ".\n";
	cout << "Swapping as int& arguments...\n";
	swap(third, fourth);
	cout << "Now the numbers are " << third << " and " << fourth << ".\n";
    return 0;
}

