/* 
	5.5.2.cpp : Write a program that prints out the letters a through z along with their ASCII codes. Hint: to print
	characters as integers, you have to use a static_cast.
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	char c{ 'a' };
	while (c <= 'z')
	{
		cout << c << " " << static_cast<int>(c) << '\n';
		c++;
	}
    return 0;
}

