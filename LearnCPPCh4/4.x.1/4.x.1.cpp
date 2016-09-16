/* 
	4.x.1.cpp : In designing a game, we decide we want to have monsters, because everyone likes fighting monsters.
	Declare a struct that represents your monster. The monster should have a type that can be one of the following: an
	ogre, a dragon, an orc, a giant spider, or a slime. If you’re using C++11, use an enum class for this. If you’re
	using an older compiler, use an enumeration for this.

	Each individual monster should also have a name, as well as an amount of health that represents how much damage
	they can take before they die. Write a function named printMonster() that prints out all of the struct’s members.
	Instantiate an ogre and a slime, initialize them using an initializer list, and pass them to printMonster().

	Your program should produce the following output:

	This Ogre is named Torg and has 145 health.
	This Slime is named Blurp and has 23 health.
*/

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

enum class MonsterType
{
	OGRE,
	DRAGON,
	ORC,
	GIANT_SPIDER,
	SLIME
};

struct Monster
{
	MonsterType type;
	string name;
	int health;
};

string getMonsterName(MonsterType type)
{
	switch (type)
	{
	case MonsterType::OGRE:
		return "Ogre";
		
	case MonsterType::DRAGON:
		return "Dragon";

	case MonsterType::ORC:
		return "Orc";

	case MonsterType::GIANT_SPIDER:
		return "Giant Spider";

	case MonsterType::SLIME:
		return "Slime";

	default:
		return "<UNDEFINED>";
	}
}

void printMonster(Monster monster)
{
	cout << "This " << getMonsterName(monster.type) << " is named " << monster.name << " and has " << monster.health 
		<< " health.\n";
}

int main()
{
	Monster ogre{ MonsterType::OGRE, "Torg", 145 };
	Monster slime{ MonsterType::SLIME, "Blurp", 23 };
	printMonster(ogre);
	printMonster(slime);
    return 0;
}

