#include "stdafx.h"
#include "Player.h"

Player::Player(string name)
	: Creature(name, '@', 10, 1, 0), m_level {1}
{
}

Player::~Player()
{
}

void Player::levelUp()
{
	m_level++;
	m_damage++;
}

int Player::getLevel()
{
	return m_level;
}

bool Player::hasWon()
{
	return (m_level >= 20);
}
