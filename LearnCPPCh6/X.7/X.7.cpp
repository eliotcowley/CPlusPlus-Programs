/* 
	X.7.cpp : Alright, challenge time! Let’s write a simplified version of Blackjack. If you’re not already familiar with
	Blackjack, the Wikipedia article for Blackjack has a summary.

	Here are the rules for our version of Blackjack:
	* The dealer gets one card to start (in real life, the dealer gets two, but one is face down so it doesn’t matter at
	this point).
	* The player gets two cards to start.
	* The player goes first.
	* A player can repeatedly hit or stand.
	* If the player stands, their turn is over.
	* If the player hits, they get another card and the value of that card is added to their total score.
	* An ace normally counts as a 1 or an 11 (whichever is better for the total score). For simplicity, we’ll count it as
	an 11 here.
	* If the player goes over a score of 21, they bust and lose immediately.
	* The dealer goes after the player.
	* The dealer repeatedly draws until they reach a score of 17 or more, at which point they stand.
	* If the dealer goes over a score of 21, they bust and the player wins immediately.
	* Otherwise, if the player has a higher score than the dealer, the player wins. Otherwise, the player loses.

	In our simplified version of Blackjack, we’re not going to keep track of which specific cards the player and the
	dealer have been dealt. We’ll only track the sum of the values of the cards they have been dealt for the player and
	dealer. This keeps things simpler.

	Start with the code you wrote in quiz #6. Create a function named playBlackjack() that returns true if the player
	wins, and false if they lose. This function should:
	* Accept a shuffled deck of cards as a parameter.
	* Initialize a pointer to the first Card named cardPtr. This will be used to deal out cards from the deck (see the
	hint below).
	* Create two integers to hold the player’s and dealer’s total score so far.
	* Implement Blackjack as defined above.

	Hint: The easiest way to deal cards from the deck is to keep a pointer to the next card in the deck that will be dealt
	out. Whenever we need to deal a card, we get the value of the current card, and then advance the pointer to point at
	the next card. This can be done in one operation:

	getCardValue(*cardPtr++);

	This returns the current card’s value (which can then be added to the player or dealer’s total), and advances cardPtr
	to the next card.

	Extra credit: Critical thinking time: Describe how you could modify the above program to handle the case where aces
	can be equal to 1 or 11.

	Hint: It’s important to note that we’re only keeping track of the sum of the cards, not which specific cards the user
	has.
*/

#include "stdafx.h"
#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>
using namespace std;

const int g_numCards{ 52 };
const int g_blackjackMax{ 21 };
const int g_dealerMax{ 17 };

enum class Rank
{
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	JACK,
	QUEEN,
	KING,
	ACE,
	MAX
};

enum class Suit
{
	CLUBS,
	DIAMONDS,
	HEARTS,
	SPADES,
	MAX
};

struct Card
{
	Rank rank;
	Suit suit;
};

void printCard(const Card &card)
{
	switch (card.rank)
	{
	case Rank::ACE:
		cout << "A";
		break;
	case Rank::TWO:
		cout << "2";
		break;
	case Rank::THREE:
		cout << "3";
		break;
	case Rank::FOUR:
		cout << "4";
		break;
	case Rank::FIVE:
		cout << "5";
		break;
	case Rank::SIX:
		cout << "6";
		break;
	case Rank::SEVEN:
		cout << "7";
		break;
	case Rank::EIGHT:
		cout << "8";
		break;
	case Rank::NINE:
		cout << "9";
		break;
	case Rank::TEN:
		cout << "T";
		break;
	case Rank::JACK:
		cout << "J";
		break;
	case Rank::QUEEN:
		cout << "Q";
		break;
	case Rank::KING:
		cout << "K";
		break;
	}

	switch (card.suit)
	{
	case Suit::CLUBS:
		cout << "C";
		break;
	case Suit::DIAMONDS:
		cout << "D";
		break;
	case Suit::HEARTS:
		cout << "H";
		break;
	case Suit::SPADES:
		cout << "S";
		break;
	}
}

void printDeck(const array<Card, g_numCards> &deck)
{
	for (const Card &card : deck)
	{
		printCard(card);
		cout << ' ';
	}
	cout << '\n';
}

void swapCard(Card &card1, Card &card2)
{
	Card temp = card1;
	card1 = card2;
	card2 = temp;
}

// Generate a random number between min and max (inclusive)
// Assumes srand() has already been called
int getRandomNumber(int min, int max)
{
	// static used for efficiency, so we only calculate this value once
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

	// evenly distribute the random number across our range
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void shuffleDeck(array<Card, g_numCards> &deck)
{
	for (int i{ 0 }; i < deck.size(); i++)
	{
		swapCard(deck.at(i), deck.at(getRandomNumber(0, g_numCards - 1)));
	}
}

int getCardValue(Card &card)
{
	switch (card.rank)
	{
	case Rank::TWO:
		return 2;
	case Rank::THREE:
		return 3;
	case Rank::FOUR:
		return 4;
	case Rank::FIVE:
		return 5;
	case Rank::SIX:
		return 6;
	case Rank::SEVEN:
		return 7;
	case Rank::EIGHT:
		return 8;
	case Rank::NINE:
		return 9;
	case Rank::TEN:
		return 10;
	case Rank::JACK:
		return 10;
	case Rank::QUEEN:
		return 10;
	case Rank::KING:
		return 10;
	case Rank::ACE:
		return 11;
	default:
		cout << "ERROR: Card rank not recognized.\n";
		return 0;
	}
}

bool playBlackjack(array<Card, g_numCards> &shuffledDeck)
{
	// Setup
	Card *cardPtr{ &shuffledDeck.at(0) };
	int playerScore{ 0 };
	int dealerScore{ 0 };

	// Dealer gets a card
	dealerScore += getCardValue(*cardPtr++);
	cout << "Dealer gets a card. Dealer's score: " << dealerScore << '\n';

	// Player gets 2 cards
	playerScore += getCardValue(*cardPtr++);
	playerScore += getCardValue(*cardPtr++);
	cout << "You get 2 cards. Score: " << playerScore << '\n';

	// Player's turn
	char c;
	cout << "Hit (h) or stand (s)? ";
	cin >> c;
	while (c == 'h')
	{
		playerScore += getCardValue(*cardPtr++);
		cout << "You draw a card. Score: " << playerScore << '\n';
		if (playerScore > g_blackjackMax)
		{
			return false;
		}
		cout << "Hit (h) or stand (s)? ";
		cin >> c;
	}

	// Dealer's turn
	while (dealerScore < g_dealerMax)
	{
		dealerScore += getCardValue(*cardPtr++);
		cout << "Dealer draws a card. Dealer's score: " << dealerScore << '\n';
	}
	if (dealerScore > g_blackjackMax)
	{
		return true;
	}
	else
	{
		if (playerScore > dealerScore)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

int main()
{
	// Initialize random numbers
	srand(static_cast<unsigned int>(time(0)));
	rand(); // Call once because of Visual Studio bug

	// Set up deck
	array<Card, g_numCards> deck;
	int card{ 0 };
	for (int rank{ 0 }; rank < static_cast<int>(Rank::MAX); rank++)
	{
		for (int suit{ 0 }; suit < static_cast<int>(Suit::MAX); suit++)
		{
			deck.at(card) = { static_cast<Rank>(rank), static_cast<Suit>(suit) };
			card++;
		}
	}

	shuffleDeck(deck);
	if (playBlackjack(deck))
	{
		cout << "You win!\n";
	}
	else
	{
		cout << "Sorry, you lose.\n";
	}

	return 0;
}

