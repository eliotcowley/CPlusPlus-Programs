/*	X7.cpp : Write a program that strips comments out of a C++ program. That is, read from cin, remove both // comments
	and block comments, and write the result to cout. Do not worry about making the layout of the output look nice (that
	would be another, and much harder, exercise). Do not worry about incorrect programs. Beware of // and block comment
	symbols in comments, strings, and character constants.
*/

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

string stripComments(string input)
{
	string out{ "" };
	bool isComment{ false };
	char lastChar;

	// Strip out // comments
	for (char c : input)
	{
		if (!isComment)
		{
			if (c == '/')
			{
				if (lastChar == '/')
				{
					isComment = true;
				}
			}
		}
		out += c;
	}
	
	return out;
}

int main()
{
	string input;
	cin >> input;
    return 0;
}

