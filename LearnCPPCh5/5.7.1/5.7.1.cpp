/* 
	5.7.1.cpp : Write a for loop that prints every even number from 0 to 20.
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	for (int i{ 0 }; i <= 20; i++)
	{
		if ((i % 2) == 0)
		{
			cout << i << '\n';
		}
	}
    return 0;
}

