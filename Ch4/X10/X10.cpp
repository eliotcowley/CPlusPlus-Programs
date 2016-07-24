// X10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<string>
#include<iostream>
#include<fstream>
#include<iterator>
#include<vector>

using namespace std;

int main()
{
	string from;
	cout << "Enter the name of the file from which to read: ";
	cin >> from;

	ifstream is{ from };
	istream_iterator<int> ii{ is };
	istream_iterator<int> eos{};

	vector<int> v{ ii, eos };

	for (int i : v)
	{
		cout << i << "\n";
	}

	return !is.eof();

	return 0;
}

