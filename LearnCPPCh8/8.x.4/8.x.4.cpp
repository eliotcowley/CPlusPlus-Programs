/* 
	8.x.4.cpp : Okay, time for that game face again. This one is going to be a challenge. Let’s rewrite the Blackjack
	games we wrote in chapter 6 using classes! Here’s the full code without classes:

	Holy moly! Where do we even begin? Don’t worry, we can do this, but we’ll need a strategy here. This Blackjack program
	is really composed of four parts: the logic that deals with cards, the logic that deals with the deck of cards, the
	logic that deals with dealing cards from the deck, and the game logic. Our strategy will be to work on each of these
	pieces individually, testing each part with a small test program as we go. That way, instead of trying to convert the
	entire program in one go, we can do it in 4 testable parts.

	Start by copying the original program into your IDE, and then commenting out everything except the #include lines.

	Let’s start by making Card a class instead of a struct. The good news is that the Card class is pretty similar to the
	Monster class from the previous quiz question. First, move the enums for CardSuit, CardRank inside the card class as
	public definitions (they’re intrinsically related to Card, so it makes more sense for them to be inside the class, not
	outside). Second, create private members to hold the CardRank and CardSuit (name them m_rank and m_suit accordingly).
	Third, create a public constructor for the Card class so we can initialize Cards. Forth, make sure to assign default
	values to the parameters so this can be used as a default constructor (pick any values you like). Finally, move the
	printCard() and getCardValue() functions inside the class as public members (remember to make them const!).

	Okay, now let’s work on a Deck class. The deck needs to hold 52 cards, so use a private std::array member to create a
	fixed array of 52 cards named m_deck. Second, create a constructor that takes no parameters and initializes m_deck
	with one of each card (modify the code from the original main() function). Inside the initialization loop, create an
	anonymous Card object and assign it to your deck element. Third, move printDeck into the Deck class as a public
	member. Fourth, move getRandomNumber() and swapCard() into the Deck class as a private static members (they’re just
	helper functions, so they don’t need access to *this). Fifth, move shuffleDeck into the class as a public member.

	Hint: The trickiest part of this step is initializing the deck using the modified code from the original main()
	function. The following line shows how to do that.

	m_deck[card] = Card(static_cast<Card::CardRank>(rank), static_cast<Card::CardSuit>(suit));

	Now we need a way to keep track of which card is next to be dealt (in the original program, this is what cardptr was
	for). First, add an int member named m_cardIndex and initialize it to 0. Create a public member function named
	dealCard(), which should return a const reference to the current card and advance the index. shuffleDeck() should also
	be updated to reset m_cardIndex (since if you shuffle the deck, you’ll start dealing from the top of the deck again).

	Almost there! Now, just fix up the remaining program to use the classes you wrote above. Since most of the
	initialization routines has been moved into the classes, you can jettison them.
*/

#include "stdafx.h"
#include <iostream>
#include <array>
#include <ctime> // for time()
#include <cstdlib> // for rand() and srand()
#include "Card.h"
#include "Deck.h"

char getPlayerChoice()
{
	std::cout << "(h) to hit, or (s) to stand: ";
	char choice;
	do
	{
		std::cin >> choice;
	} while (choice != 'h' && choice != 's');

	return choice;
}

bool playBlackjack(Deck deck)
{
	// Set up the initial game state
	int playerTotal = 0;
	int dealerTotal = 0;

	// Deal the player one card
	dealerTotal += deck.dealCard().getCardValue();
	std::cout << "The dealer is showing: " << dealerTotal << '\n';

	// Deal the player two cards
	playerTotal += deck.dealCard().getCardValue();
	playerTotal += deck.dealCard().getCardValue();

	// Player goes first
	while (1)
	{
		std::cout << "You have: " << playerTotal << '\n';
		char choice = getPlayerChoice();
		if (choice == 's')
			break;

		playerTotal += deck.dealCard().getCardValue();

		// See if the player busted
		if (playerTotal > 21)
			return false;
	}

	// If player hasn't busted, dealer goes until he has at least 17 points
	while (dealerTotal < 17)
	{
		dealerTotal += deck.dealCard().getCardValue();
		std::cout << "The dealer now has: " << dealerTotal << '\n';
	}

	// If dealer busted, player wins
	if (dealerTotal > 21)
		return true;

	return (playerTotal > dealerTotal);
}

int main()
{
	srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
	rand(); // If using Visual Studio, discard first random value

	Deck deck;

	deck.shuffleDeck();

	if (playBlackjack(deck))
		std::cout << "You win!\n";
	else
		std::cout << "You lose!\n";

	return 0;
}