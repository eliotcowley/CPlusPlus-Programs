/* 
	5.5.4.cpp : Now make the numbers print like this:

			1
		  2 1
		3 2 1
	  4 3 2 1
	5 4 3 2 1

	hint: Figure out how to make it print like this first:

	X X X X 1
	X X X 2 1
	X X 3 2 1
	X 4 3 2 1
	5 4 3 2 1
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int outer = 1;
	while (outer <= 5)
	{
		// loop between outer and 1
		int inner = 5;
		while (inner >= 1)
		{
			if (inner <= outer)
			{
				cout << inner << " ";
			}
			else
			{
				cout << "  ";
			}
			inner--;
		}

		// print a newline at the end of each row
		std::cout << "\n";
		++outer;
	}
    return 0;
}

