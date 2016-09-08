/* 
	X4.cpp : Define a struct Date to keep track of dates. Provide functions that read Dates from input, write Dates to
	output, and initialize a Date with a date.
*/

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

struct Date
{
	int month;
	int day;
	int year;
};

Date makeDate(int month, int day, int year)
{
	Date d{ month, day, year };
	return d;
}

void writeDate(Date date)
{
	cout << "The date is " << date.month << '/' << date.day << '/' << date.year << '\n';
}

Date readDate(string date)
{
	int part{ 0 };
	string s;
	int month;
	int day;
	int year;
	for (int i{ 0 }; i < date.length(); i++)
	{
		if (date[i] == '/')
		{
			if (part == 0)
			{
				month = stoi(s);
			}
			else if (part == 1)
			{
				day = stoi(s);
			}
			part++;
			s = "";
			continue;
		}
		s.push_back(date[i]);
	}
	year = stoi(s);
	return makeDate(month, day, year);
}

int main()
{
	cout << "Enter a date: ";
	string date;
	cin >> date;
	Date d = readDate(date);
	writeDate(d);

    return 0;
}

