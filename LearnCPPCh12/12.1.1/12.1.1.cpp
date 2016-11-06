/* 
	12.1.1.cpp : Our Animal/Cat/Dog example above doesn’t work like we want because a reference or pointer to an Animal can’t access the derived version
	of speak() needed to return the right value for the Cat or Dog. One way to work around this issue would be to make the data returned by the speak()
	function accessible as part of the Animal base class (much like the Animal’s name is accessible via member m_name).

	Update the Animal, Cat, and Dog classes in the lesson above by adding a new member to Animal named m_speak. Initialize it appropriately. The
	following program should work properly:

	#include <iostream>
 
	int main()
	{
    	Cat fred("Fred"), misty("Misty"), zeke("Zeke");
    	Dog garbo("Garbo"), pooky("Pooky"), truffle("Truffle");
 
    	// Set up an array of pointers to animals, and set those pointers to our Cat and Dog objects
    	Animal *animals[] = { &fred, &garbo, &misty, &pooky, &truffle, &zeke };
    	for (int iii=0; iii < 6; iii++)
        	std::cout << animals[iii]->getName() << " says " << animals[iii]->speak() << '\n';
 
    	return 0;
	}
*/

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

class Animal
{
protected:
	std::string m_name;
	string m_speak;

	// We're making this constructor protected because
	// we don't want people creating Animal objects directly,
	// but we still want derived classes to be able to use it.
	Animal(std::string name, string speak)
		: m_name(name), m_speak {speak}
	{
	}

public:
	std::string getName() { return m_name; }
	string speak() { return m_speak; }
};

class Cat : public Animal
{
public:
	Cat(std::string name)
		: Animal(name, "Meow")
	{
	}

	string speak() { return m_speak; }
};

class Dog : public Animal
{
public:
	Dog(std::string name)
		: Animal(name, "Woof")
	{
	}

	string speak() { return m_speak; }
};

int main()
{
	Cat fred("Fred"), misty("Misty"), zeke("Zeke");
	Dog garbo("Garbo"), pooky("Pooky"), truffle("Truffle");

	// Set up an array of pointers to animals, and set those pointers to our Cat and Dog objects
	Animal *animals[] = { &fred, &garbo, &misty, &pooky, &truffle, &zeke };
	for (int iii = 0; iii < 6; iii++)
		std::cout << animals[iii]->getName() << " says " << animals[iii]->speak() << '\n';

    return 0;
}