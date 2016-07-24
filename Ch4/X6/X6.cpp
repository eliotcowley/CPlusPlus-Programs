// X6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<string>
#include<iostream>

using namespace std;

struct NameAgePair
{
	string name;
	int age;
};

ostream& operator<<(ostream& os, const NameAgePair& nap)
{
	return os << "{\"" << nap.name << "\", " << nap.age << "}";
}

istream& operator >> (istream& is, NameAgePair& nap)
{
	// read {"name", age} pair
	char c, c2;
	if (is >> c && c == '{' && is >> c2 && c2 == '"') // start with a {"
	{
		string name;
		while (is.get(c) && c != '"')	// anything before " is part of name
		{
			name += c;
		}
		if (is >> c && c == ',')
		{
			int age = 0;
			if (is >> age >> c && c == '}')	// read age and }
			{
				nap = { name, age };	// assign to nap
				return is;
			}
		}
	}
	is.setstate(ios_base::failbit);	// register the failure in the stream
	return is;
}

int main()
{
	NameAgePair nap = { "Eliot Cowley", 23 };
	NameAgePair myNap;

	cout << nap << "\n";
	cout << "Please enter a name/age pair.\n";
	cin >> myNap;
	cout << myNap << "\n";

    return 0;
}

