/* 
	X2.cpp : Define a table of the names of months of the year and the number of days in each month. Write out that table.
	Do this twice; once using an array of char for the names and an array for the number of days and once using an array
	of structures, with each structure holding the name of a month and the number of days in it.
*/

#include "stdafx.h"
#include <string>
using namespace std;

// Structure for month with name of month and number of days
struct month
{
	string name;
	int days;
};

int main()
{
	// Array of char* for names of months, array of int for numbers of days
	char* names[] = 
	{ 
		"January", 
		"February", 
		"March", 
		"April", 
		"May", 
		"June", 
		"July", 
		"August", 
		"September", 
		"October", 
		"November", 
		"December" 
	};

	int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	// Declare and initialize months
	month january{ "January", 31 };
	month february{ "February", 28 };
	month march{ "March", 31 };
	month april{ "April", 30 };
	month may{ "May", 31 };
	month june{ "June", 30 };
	month july{ "July", 31 };
	month august{ "August", 31 };
	month september{ "September", 30 };
	month october{ "October", 31 };
	month november{ "November", 30 };
	month december{ "December", 31 };

	// Put month structs into array
	month months[] = 
	{
		january,
		february,
		march,
		april,
		may,
		june,
		july,
		august,
		september,
		october,
		november,
		december
	};

    return 0;
}

