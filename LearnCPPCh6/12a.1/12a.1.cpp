/* 
	12a.1.cpp : Declare a fixed array with the following names: Alex, Betty, Caroline, Dave, Emily, Fred, Greg, and Holly.
	Ask the user to enter a name. Use a for each loop to see if the name the user entered is in the array.

	Sample output:

	Enter a name: Betty
	Betty was found.
	Enter a name: Megatron
	Megatron was not found.

	Hint: Use std::string as your array type.
*/

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
	string names[] = { "Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly" };
	while (true)
	{
		cout << "Enter a name: ";
		string input;
		cin >> input;
		bool found{ false };
		for (auto &name : names)
		{
			if (input == name)
			{
				found = true;
			}
		}
		if (found)
		{
			cout << input << " was found.\n";
		}
		else
		{
			cout << input << " was not found.\n";
		}
	}

    return 0;
}

