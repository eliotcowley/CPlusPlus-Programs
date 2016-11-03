/* 
	11.x.2.cpp : a) Write an Apple class and a Banana class that are derived from a common Fruit class. Fruit should have two members: a name, and a
	color.

	The following program should run:

	int main()
	{
		Apple a("red");
		Banana b;
 
		std::cout << "My " << a.getName() << " is " << a.getColor() << '.\n';
		std::cout << "My " << b.getName() << " is " << b.getColor() << '.\n';
	
		return 0;
	}

	And produce the result:

	My apple is red.
	My banana is yellow.

	b) Add a new class to the previous program called GrannySmith that inherits from Apple.

	The following program should run:

	int main()
	{
		Apple a("red");
		Banana b;
		GrannySmith c;
 
		std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
		std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
		std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
	
		return 0;
	}
	And produce the result:

	My apple is red.
	My banana is yellow.
	My granny smith apple is green.
*/

#include "stdafx.h"
#include "Apple2.h"
#include "Banana2.h"
#include "GrannySmith.h"
#include <iostream>

int main()
{
	Apple2 a("red");
	Banana2 b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    return 0;
}

