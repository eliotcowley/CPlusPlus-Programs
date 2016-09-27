/* 
	X.1.cpp : Pretend you’re writing a game where the player can hold 3 types of items: health potions, torches, and
	arrows. Create an enum to identify the different types of items, and a fixed array to store the number of each item
	the player is carrying (use built-in fixed arrays, not std::array). The player should start with 2 health potions, 5
	torches, and 10 arrows. Write a function called countTotalItems() that returns how many items the player has in total.
	Have your main() function print the output of countTotalItems().
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

enum class Item
{
	HEALTH_POTION,
	TORCH,
	ARROW,
};

int countTotalItems(int *array, int length)
{
	int total{ 0 };
	for (int i{ 0 }; i < length; i++)
	{
		total += array[i];
	}
	return total;
}

int main()
{
	const int length{ 3 };
	int items[length]{ 2, 5, 10 };
	cout << countTotalItems(items, length) << '\n';
    return 0;
}

