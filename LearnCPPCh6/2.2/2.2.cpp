/* 
	2.2.cpp : Set up an enum with the names of the following animals: chicken, dog, cat, elephant, duck, and snake. Put
	the enum in a namespace. Define an array with an element for each of these animals, and use an initializer list to
	initialize each element to hold the number of legs that animal has.

	Write a main function that prints the number of legs an elephant has, using the enumerator.
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

namespace Animals
{
	enum Animal
	{
		CHICKEN,	// 0
		DOG,		// 1
		CAT,		// ...
		ELEPHANT,
		DUCK,
		SNAKE,		// 5
		MAX_ANIMALS
	};
}

int main()
{
	int animals[] = { 2, 4, 4, 4, 2, 0 };
	cout << "Elephants have " << animals[Animals::ELEPHANT] << " legs.\n";
    return 0;
}

