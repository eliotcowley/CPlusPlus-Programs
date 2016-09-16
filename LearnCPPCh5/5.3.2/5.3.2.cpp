/* 
	5.3.2.cpp : Define an enum (or enum class, if using a C++11 capable compiler) named Animal that contains the
	following animals: pig, chicken, goat, cat, dog, ostrich. Write a function named getAnimalName() that takes an
	Animal parameter and uses a switch statement to return the name for that animal as a std::string. Write another
	function named printNumberOfLegs that uses a switch statement to print the number of legs each animal walks on.
	Make sure both functions have a default case that prints an error message. Call printNumberOfLegs() from main()
	with a cat and a chicken. Your output should look like this:
	
	A cat has 4 legs.
	A chicken has 2 legs.
*/

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

enum class Animal
{
	PIG,
	CHICKEN,
	GOAT,
	CAT,
	DOG,
	OSTRICH
};

string getAnimalName(Animal animal)
{
	switch (animal)
	{
	case Animal::CAT:
		return "cat";
	case Animal::CHICKEN:
		return "chicken";
	case Animal::DOG:
		return "dog";
	case Animal::GOAT:
		return "goat";
	case Animal::OSTRICH:
		return "ostrich";
	case Animal::PIG:
		return "pig";
	default:
		cerr << "ERROR: Animal not recognized\n";
		exit(1);
	}
}

void printNumberOfLegs(Animal animal)
{
	int legs;
	switch (animal)
	{
	case Animal::CAT:
	case Animal::DOG:
	case Animal::GOAT:
	case Animal::PIG:
		legs = 4;
		break;
	case Animal::CHICKEN:
	case Animal::OSTRICH:
		legs = 2;
		break;		
	default:
		cerr << "ERROR: Animal not recognized\n";
		exit(1);
	}
	cout << "A " << getAnimalName(animal) << " has " << legs << " legs.\n";
}

int main()
{
	printNumberOfLegs(Animal::CAT);
	printNumberOfLegs(Animal::CHICKEN);
    return 0;
}

