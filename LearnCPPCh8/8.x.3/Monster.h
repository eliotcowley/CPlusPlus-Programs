#pragma once

#include <string>

using namespace std;

class Monster
{
public:
	enum MonsterType
	{
		Dragon,
		Goblin,
		Ogre,
		Orc,
		Skeleton,
		Troll,
		Vampire,
		Zombie,
		MAX_MONSTER_TYPES
	};

	Monster(MonsterType type, string name, string roar, int hitPoints);
	~Monster();

	string getTypeString();
	void print();

private:
	MonsterType m_type;
	string m_name;
	string m_roar;
	int m_hitPoints;
};

