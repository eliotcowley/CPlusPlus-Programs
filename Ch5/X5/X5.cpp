// X5.cpp : Use a regex to find all decimal numbers in a file.

#include "stdafx.h"
#include <regex>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	regex pat(R"(\d+\.\d+)");
	int lineno = 0;
	string from;
	cout << "Enter the name of the file from which to read: ";
	cin >> from;
	ifstream is{ from };
	for (string line; !is.eof();)
	{
		++lineno;
		smatch matches;
		getline(is, line);
		if (regex_search(line, matches, pat))
		{
			cout << lineno << ": " << matches[0] << '\n';
		}
	}
    return 0;
}

