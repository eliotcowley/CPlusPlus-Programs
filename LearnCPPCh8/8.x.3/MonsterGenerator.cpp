#include "stdafx.h"
#include "MonsterGenerator.h"

/* Dragon,
Goblin,
Ogre,
Orc,
Skeleton,
Troll,
Vampire,
Zombie,*/



Monster MonsterGenerator::generateMonster()
{
	Monster::MonsterType type{ static_cast<Monster::MonsterType>(getRandomNumber(0, Monster::MAX_MONSTER_TYPES - 1)) };
	int hitPoints{ getRandomNumber(1, 100) };

	static string s_names[6]{ "Drogon", "Gobby", "Shrek", "Orca", "Jack", "Trololol" };
	static string s_roars[6]{ "*roar*", "*hehehe*", "*shreked*", "*arrrg*", "*rattle*", "*trololol*" };

	string name{ s_names[getRandomNumber(0, 5)] };
	string roar{ s_roars[getRandomNumber(0, 5)] };

	return Monster{ type, name, roar, hitPoints };
}

// Generate a random number between min and max (inclusive)
// Assumes srand() has already been called
int MonsterGenerator::getRandomNumber(int min, int max)
{
	// static used for efficiency, so we only calculate this value once
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

	// evenly distribute the random number across our range
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
