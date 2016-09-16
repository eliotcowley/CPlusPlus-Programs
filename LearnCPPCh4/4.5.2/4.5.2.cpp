/*
	4.5.2.cpp : Declare a variable of the enumerated type you defined in question 1 and assign it the troll type.
*/

#include "stdafx.h"

enum Monster
{
	MONSTER_ORC,
	MONSTER_GOBLIN,
	MONSTER_TROLL,
	MONSTER_OGRE,
	MONSTER_SKELETON
};

int main()
{
	Monster orc{ MONSTER_ORC };
	return 0;
}

