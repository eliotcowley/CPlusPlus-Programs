#include "stdafx.h"
#include "Creature.h"

Creature::Creature(string name, char symbol, int health, int damage, int gold)
	: m_name {name}, m_symbol {symbol}, m_health {health}, m_damage {damage}, m_gold {gold}
{
}

Creature::~Creature()
{
}

string Creature::getName()
{
	return m_name;
}

char Creature::getSymbol()
{
	return m_symbol;
}

int Creature::getHealth()
{
	return m_health;
}

int Creature::getDamage()
{
	return m_damage;
}

int Creature::getGold()
{
	return m_gold;
}

void Creature::reduceHealth(int amount)
{
	m_health -= amount;
}

bool Creature::isDead()
{
	return (m_health <= 0);
}

void Creature::addGold(int amount)
{
	m_gold += amount;
}
