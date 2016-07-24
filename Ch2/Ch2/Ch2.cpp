// Ch2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	std::cout << "Hello, World!\n";
	cout << "Enter a boolean:\n";
	bool myBool;
	cin >> myBool;
	cout << "Enter a char:\n";
	char myChar;
	cin >> myChar;
	cout << "Enter an int:\n";
	int myInt;
	cin >> myInt;
	cout << "Enter a double:\n";
	double myDouble;
	cin >> myDouble;
	cout << "Enter a string:\n";
	string myString;
	cin >> myString;
	cout << "Your bool: " << myBool << "\n";
	cout << "Your char: " << myChar << "\n";
	cout << "Your int: " << myInt << "\n";
	cout << "Your double: " << myDouble << "\n";
	cout << "Your string: " << myString << "\n";
}

