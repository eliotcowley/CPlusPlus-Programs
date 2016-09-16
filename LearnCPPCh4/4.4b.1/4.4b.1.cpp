/* 
	4.4b.1.cpp : Write a program that asks the user to enter their full name and their age. As output, tell the user
	how many years they’ve lived for each letter in their name (for simplicity, count spaces as a letter).

	Sample output :
	Enter your full name : John Doe
	Enter your age : 46
	You've lived 5.75 years for each letter in your name.
*/

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	cout << "Enter your full name: ";
	string name;
	getline(cin, name);
	cout << "Enter your age: ";
	int age;
	cin >> age;
	double yearsPerChar = static_cast<double>(age) / static_cast<double>(name.length());
	cout << "For each letter in your name, you've lived approximately " << yearsPerChar << " years.\n";

    return 0;
}

