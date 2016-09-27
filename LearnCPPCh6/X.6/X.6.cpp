/* 
	X.6.cpp : Let’s pretend we’re writing a card game.

	A deck of cards has 52 unique cards (13 card ranks of 4 suits). Create enumerations for the card ranks (2, 3, 4, 5, 6,
	7, 8, 9, 10, Jack, Queen, King, Ace) and suits (clubs, diamonds, hearts, spades).

	Each card will be represented by a struct named Card that contains a rank and a suit. Create the struct.

	Create a printCard() function that takes a const Card reference as a parameter and prints the card rank and value as a
	2-letter code (e.g. the jack of spades would print as JS).

	A deck of cards has 52 cards. Create an array (using std::array) to represent the deck of cards, and initialize it
	with one of each card.

	Hint: Use static_cast if you need to convert an integer into an enumerated type.

	Write a function named printDeck() that takes the deck as a const reference parameter and prints the values in the
	deck. Use a for-each loop.

	Write a swapCard function that takes two Cards and swaps their values.

	Write a function to shuffle the deck of cards called shuffleDeck(). To do this, use a for loop to step through each
	element of your array. Pick a random number between 1 and 52, and call swapCard with the current card and the card
	picked at random. Update your main function to shuffle the deck and print out the shuffled deck.

	Hint: Review lesson 5.9 -- Random number generation for help with random numbers.
	Hint: Don’t forget to call srand() at the top of your main function.
	Hint: If you’re using Visual Studio, don’t forget to call rand() once before using rand.

	Write a function named getCardValue() that returns the value of a Card (e.g. a 2 is worth 2, a ten, jack, queen, or
	king is worth 10. Assume an Ace is worth 11).
*/

#include "stdafx.h"
#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>
using namespace std;

const int g_numCards{ 52 };

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
		swapCard(deck.at(i), deck.at(getRandomNumber(0, g_numCards-1)));
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

int main()
{
	// Initialize random numbers
	srand(static_cast<unsigned int>(time(0)));
	rand(); // Call once because of Visual Studio bug

	// Set up deck
	array<Card, g_numCards> deck;
	int card{ 0 };
	for (int rank {0}; rank < static_cast<int>(Rank::MAX); rank++)
	{
		for (int suit{ 0 }; suit < static_cast<int>(Suit::MAX); suit++)
		{
			deck.at(card) = { static_cast<Rank>(rank), static_cast<Suit>(suit) };
			card++;
		}
	}
	printDeck(deck);

	shuffleDeck(deck);
	printDeck(deck);

    return 0;
}

