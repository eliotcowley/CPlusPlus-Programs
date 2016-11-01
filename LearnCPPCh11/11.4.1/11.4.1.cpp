/* 
	11.4.1.cpp : Let’s implement our Fruit example that we talked about in our introduction to inheritance. Create a Fruit base class that contains two
	private members: a name (std::string), and a color (std::string). Create an Apple class that inherits Fruit. Apple should have an additional private
	member: fiber (double). Create a Banana class that also inherits Fruit. Banana has no additional members.

	The following program should run:

	int main()
	{
		const Apple a("Red delicious", "red", 4.2);
		std::cout << a;
 
		const Banana b("Cavendish", "yellow");
		std::cout << b;
 
		return 0;
	}

	And print the following:

	Apple(Red delicious, red, 4.2)
	Banana(Cavendish, yellow)

	Hint: Because a and b are const, you’ll need to mind your const’s. Make sure your parameters and functions are appropriately const.
*/

#include "stdafx.h"
#include "Apple.h"
#include "Banana.h"
#include <iostream>

int main()
{
	const Apple a("Red delicious", "red", 4.2);
	std::cout << a;

	const Banana b("Cavendish", "yellow");
	std::cout << b;

    return 0;
}

