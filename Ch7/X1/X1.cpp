/*	
	X1.cpp : Write declarations for the following: a pointer to a character, an array of 10 integers, a reference to an
	array of 10 integers, a pointer to an array of character strings, a pointer to a pointer to a character, a constant
	integer, a pointer to a constant integer, and a constant pointer to an integer. Initialize each one.
*/

#include "stdafx.h"


int main()
{
	char c{ 'c' };
	char* pc{ &c };

	int myArray[10] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int& myArrayRef{ *myArray };

	char charArray[]{ 'h', 'e', 'l', 'l', 'o' };
	char* pcharArray{ charArray };

	char** ppc{ &pc };

	const int constInt{ 1 };

	const int* pConstInt{ &constInt };

	int i{ 1 };
	int *const cpi{ &i };

    return 0;
}

