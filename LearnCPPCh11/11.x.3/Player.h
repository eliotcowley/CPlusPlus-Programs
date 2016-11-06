#pragma once

#include "Creature.h"

class Player :
	public Creature
{
public:
	Player(string name);
	~Player();
	void levelUp();
	int getLevel();
	bool hasWon();

private:
	int m_level;
};

