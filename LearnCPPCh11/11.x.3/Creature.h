#pragma once

#include <string>

using namespace std;

class Creature
{
public:
	Creature(string name, char symbol, int health, int damage, int gold);
	~Creature();
	string getName();
	char getSymbol();
	int getHealth();
	int getDamage();
	int getGold();
	void reduceHealth(int amount);
	bool isDead();
	void addGold(int amount);

protected:
	string m_name;
	char m_symbol;
	int m_health;
	int m_damage;
	int m_gold;
};

