#include "stdafx.h"
#include "Monster.h"
#include <iostream>

using namespace std;

Monster::Monster(MonsterType type, string name, string roar, int hitPoints)
	: m_type {type}, m_name {name}, m_roar {roar}, m_hitPoints {hitPoints}
{
}

Monster::~Monster()
{
}

string Monster::getTypeString()
{
	switch (m_type)
	{
	case Dragon:
		return "dragon";
	case Goblin:
		return "goblin";
	case Ogre:
		return "ogre";
	case Orc:
		return "orc";
	case Skeleton:
		return "skeleton";
	case Troll:
		return "troll";
	case Vampire:
		return "vampire";
	case Zombie:
		return "zombie";
	default:
		return "ERROR";
	}
}

void Monster::print()
{
	cout << m_name << " the " << getTypeString() << " has " << m_hitPoints << " hit points and says " 
		<< m_roar << "\n";
}
