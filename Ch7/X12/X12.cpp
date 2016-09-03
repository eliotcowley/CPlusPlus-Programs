/* 
	X12.cpp : Write a function that counts the number of occurrences of a pair of letters in a string and another that
	does the same in a zero-terminated array of char (a C-style string). For example, the pair "ab" appears twice in
	"xabaacbaxabb".
*/

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

int countNumPairsInString(string s, string pair)
{
	int count{ 0 };
	if (pair.length() != 2)
	{
		cerr << "ERROR: You must use a two-character string to search for pairs.\n";
		return 0;
	}
	for (int i{ 0 }; i < s.length() - 1; i++)
	{
		if (s[i] == pair[0])
		{
			if (s[i + 1] == pair[1])
			{
				count++;
			}
		}
	}
	return count;
}

int countNumPairsInCharArray(char s[], string pair)
{
	int count{ 0 };
	if (pair.length() != 2)
	{
		cerr << "ERROR: You must use a two-character string to search for pairs.\n";
		return 0;
	}
	int size{ 0 };
	int i{ 0 };
	while (s[i] != 0)
	{
		size++;
		i++;
	}
	for (int i{ 0 }; i < size-1; i++)
	{
		if (s[i] == pair[0])
		{
			if (s[i + 1] == pair[1])
			{
				count++;
			}
		}
	}
	return count;
}

int main()
{
	cout << "Enter a string: ";
	string s;
	cin >> s;
	cout << "Enter a pair: ";
	string pair;
	cin >> pair;
	cout << "Number of pairs found in string: " << countNumPairsInString(s, pair) << '\n';

	cout << "Enter the size of the char array: ";
	int size{ 0 };
	cin >> size;
	cout << "Enter the char array: ";
	char* cArray = new char[size];
	cin >> cArray;
	cout << "Enter a pair: ";
	string pair2;
	cin >> pair2;
	cout << "Number of pairs found in char array: " << countNumPairsInCharArray(cArray, pair2) << '\n';

    return 0;
}

