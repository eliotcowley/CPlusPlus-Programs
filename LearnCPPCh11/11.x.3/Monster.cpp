#include "stdafx.h"
#include "Monster.h"

Monster::Monster(Type type)
	: Creature(monsterData[type].name, monsterData[type].symbol, monsterData[type].health, monsterData[type].damage, monsterData[type].gold)
{
}

Monster::~Monster()
{
}

Monster Monster::getRandomMonster()
{
	return Monster{ static_cast<Type>(getRandomNumber(0, Type::MAX_TYPES - 1)) };
}

// Generate a random number between min and max (inclusive)
// Assumes srand() has already been called
int Monster::getRandomNumber(int min, int max)
{
	// static used for efficiency, so we only calculate this value once
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

	// evenly distribute the random number across our range
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

Monster::MonsterData Monster::monsterData[Type::MAX_TYPES]
{
	{ "dragon", 'D', 20, 4, 100 },
	{ "orc", 'o', 4, 2, 25 },
	{ "slime", 's', 1, 1, 10 },
};