/* 
	StringManipulation.cpp : Write a program that asks the user for two words and tells them which is longer.
*/

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
	string word1, word2;

	cout << "Enter word 1: ";
	cin >> word1;
	cout << "Enter word 2: ";
	cin >> word2;

	unsigned int length1{ word1.length() };
	unsigned int length2{ word2.length() };

	if (length1 > length2)
	{
		cout << word1 << " is longer.\n";
	}
	else if (length2 > length1)
	{
		cout << word2 << " is longer.\n";
	}
	else
	{
		cout << word1 << " and " << word2 << " are the same length.\n";
	}

    return 0;
}