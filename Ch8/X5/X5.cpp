/* 
	X5.cpp : Implement an enum called Season with enumerators spring, summer, autumn, and winter. Define operators ++
	and -- for Season. Define input (>>) and output (<<) operations for Season, providing string values. Provide a way
	to control the mapping between Season values and their string representations. For example, I might want the
	strings to reflect the Danish names for the seasons.
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
using namespace std;

const int numSeasons{ 4 };

enum class Season
{
	spring,
	summer,
	autumn,
	winter
};

map<Season, string> seasons;

// Prefix (++Season)
Season& operator++(Season& s)
{
	int i{ static_cast<int>(s) };
	if (((i + 1) % numSeasons) == 0)
	{
		s = Season::spring;
	}
	else
	{
		s = static_cast<Season>(static_cast<int>(s) + 1);
	}
	return s;
}

// Postfix (Season++)
Season operator++(Season& s, int)
{
	Season rValue{ s };
	++s;
	return rValue;
}

// Prefix (--Season)
Season& operator--(Season& s)
{
	int i{ static_cast<int>(s) };
	if ((i - 1) < 0)
	{
		s = Season::winter;
	}
	else
	{
		s = static_cast<Season>(i - 1);
	}
	return s;
}

// Postfix (Season--)
Season operator--(Season& s, int)
{
	Season rValue{ s };
	--s;
	return rValue;
}

// Input (>> Season)
istream& operator>>(istream& in, Season &s)
{
	string str{ "" };
	in >> str;

	if (str == seasons[Season::spring])
	{
		s = Season::spring;
	}
	else if (str == seasons[Season::summer])
	{
		s = Season::summer;
	}
	else if (str == seasons[Season::autumn])
	{
		s = Season::autumn;
	}
	else if (str == seasons[Season::winter])
	{
		s = Season::winter;
	}
	else
	{
		cerr << "Season not recognized\n";
	}
	return in;
}

// Output (<< Season)
ostream& operator<<(ostream& out, const Season& s)
{
	out << seasons[s];
	return out;
}

void fillTable()
{
	seasons[Season::spring] = "Spring";
	seasons[Season::summer] = "Summer";
	seasons[Season::autumn] = "Autumn";
	seasons[Season::winter] = "Winter";
}

int main()
{
	fillTable();

	cout << "Please enter a season: ";
	Season s;
	cin >> s;
	cout << "You entered " << s << '\n';
	cout << "Using prefix ++ operator: The next season is " << ++s << '\n';
	cout << "Using postfix ++ operator: " << s++ << '\n';
	cout << "However, the season is now: " << s << '\n';
	cout << "Using prefix -- operator: " << --s << '\n';
	cout << "Using postfix -- operator: " << s-- << '\n';
	cout << "However, the season is now: " << s << '\n';

    return 0;
}

