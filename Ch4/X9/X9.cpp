// X9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<string>
#include<iostream>
#include<fstream>
#include<iterator>

using namespace std;

int main()
{
	string to;
	cout << "Enter the name of the file to which to write: ";
	cin >> to;

	ofstream os{ to };
	ostream_iterator<string> oo{ os, "\n" };

	os << 1 << 2 << 3;

	return !os;

    return 0;
}

