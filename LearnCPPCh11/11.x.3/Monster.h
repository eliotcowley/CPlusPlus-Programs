#pragma once

#include "Creature.h"

class Monster :
	public Creature
{
public:
	enum Type
	{
		DRAGON,
		ORC,
		SLIME,
		MAX_TYPES
	};

	struct MonsterData
	{
		string name;
		char symbol;
		int health;
		int damage;
		int gold;
	};

	Monster(Type type);
	~Monster();

	static MonsterData monsterData[];
	static Monster getRandomMonster();
	static int getRandomNumber(int min, int max);
};

