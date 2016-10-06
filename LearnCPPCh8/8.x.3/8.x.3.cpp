/* 
	8.x.3.cpp : Let’s create a random monster generator. This one should be fun.

	First, let’s create an enumeration of monster types named MonsterType. Include the following monster types: Dragon,
	Goblin, Ogre, Orc, Skeleton, Troll, Vampire, and Zombie. Add an additional MAX_MONSTER_TYPES enum so we can count how
	many enumerators there are.

	Now, let’s create our Monster class. Our Monster will have 4 attributes (member variables): a type (MonsterType), a
	name (std::string), a roar (std::string), and the number of hit points (int). Create a Monster class that has these 4
	member variables.

	enum MonsterType is specific to Monster, so move the enum inside the class as a public declaration.

	Create a constructor that allows you to initialize all of the member variables.

	Now we want to be able to print our monster so we can validate it’s correct. To do that, we’re going to need to write
	a function that converts a MonsterType into a std::string. Write that function (called getTypeString()), as well as a
	print() member function.

	main should print:

	Bones the skeleton has 4 hit points and says *rattle*

	Now we can create a random monster generator. Let’s consider how our MonsterGenerator class will work. Ideally, we’ll
	ask it to give us a Monster, and it will create a random one for us. We don’t need more than one MonsterGenerator.
	This is a good candidate for a static class (one in which all functions are static). Create an empty MonsterGenerator
	class. Create a static function named generateMonster(). This should return a Monster. For now, make it return
	anonymous Monster(Monster::Skeleton, “Bones”, “*rattle*”, 4);

	main should print:

	Bones the skeleton has 4 hit points and says *rattle*

	Now, MonsterGenerator needs to generate some random attributes. To do that, we’ll need to make use of this handy
	function:

	However, because MonsterGenerator relies directly on this function, let’s put it inside the class, as a static
	function.

	Now edit function generateMonster() to generate a random MonsterType (between 0 and Monster::MAX_MONSTER_TYPES-1) and
	a random hit points (between 1 and 100). This should be fairly straightforward. Once you’ve done that, define two
	static fixed arrays of size 6 inside the function (named s_names and s_roars) and initialize them with 6 names and 6
	sounds of your choice. Pick a random name from these arrays.
*/

#include "stdafx.h"
#include "Monster.h"
#include "MonsterGenerator.h"
#include <ctime> // for time()
#include <cstdlib> // for rand() and srand()

int main()
{
	srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
	rand(); // If using Visual Studio, discard first random value

	Monster m = MonsterGenerator::generateMonster();
	m.print();

	return 0;
}

