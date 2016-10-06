#pragma once

#include <array>
#include "Card.h"

using namespace std;

class Deck
{
public:
	Deck();
	~Deck();

	void printDeck();
	void shuffleDeck();
	const Card &dealCard();

private:
	array<Card, 52> m_deck;
	static int getRandomNumber(int min, int max);
	static void swapCard(Card & a, Card & b);
	int m_cardIndex;
};

