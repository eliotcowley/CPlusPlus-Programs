/* 
	X.4.cpp : Write a function to print a C-style string character by character. Use a pointer to step through each
	character of the string and print that character. Stop when you hit a null terminator. Write a main function that
	tests the function with the string literal “Hello, world!”.

	Hint: Use operator++ to advance the pointer to the next character
*/

#include "stdafx.h"
#include <iostream> 
using namespace std;

void printCString(char *string)
{
	while (*string != '\0')
	{
		cout << *string;
		string++;
	}
}

int main()
{
	printCString("Hello, world!\n");
    return 0;
}

