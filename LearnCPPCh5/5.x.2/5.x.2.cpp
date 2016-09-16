/* 
	5.x.2.cpp : Implement a game of hi-lo. First, your program should pick a random integer between 1 and 100. The user
	is given 7 tries to guess the number. If the user does not guess the correct number, the program should tell them
	whether they guessed too high or too low. If the user guesses the right number, the program should tell them they
	won. If they run out of guesses, the program should tell them they lost, and what the correct number is. At the end
	of the game, the user should be asked if they want to play again. If the user doesn’t enter ‘y’ or ‘n’, ask them
	again.

	Here’s what your output should look like:

	Let's play a game.  I'm thinking of a number.  You have 7 tries to guess what it is.
	Guess #1: 64
	Your guess is too high.
	Guess #2: 32
	Your guess is too low.
	Guess #3: 54
	Your guess is too high.
	Guess #4: 51
	Correct! You win!
	Would you like to play again (y/n)? y
	Let's play a game.  I'm thinking of a number.  You have 7 tries to guess what it is.
	Guess #1: 64
	Your guess is too high.
	Guess #2: 32
	Your guess is too low.
	Guess #3: 54
	Your guess is too high.
	Guess #4: 51
	Your guess is too high.
	Guess #5: 36
	Your guess is too low.
	Guess #6: 45
	Your guess is too low.
	Guess #7: 48
	Your guess is too low.
	Sorry, you lose.  The correct number was 49.
	Would you like to play again (y/n)? q
	Would you like to play again (y/n)? f
	Would you like to play again (y/n)? n
	Thank you for playing.

	Hints:
	* Seed your random number generator with time(0).
	* Visual Studio users: Due to a flaw in the Visual Studio implementation of rand(), call rand() once after seeding
	to discard the first result.
	* Use the getRandomNumber() function from lesson 5.9 -- Random number generation to pick a random number.
	* Write a function that allows the user to play a single game of hi-lo.
	* Write a function that asks the user if they want to play again and handles the looping logic for an incorrect
	input.
*/

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int guesses{ 7 };

// Generate a random number between min and max (inclusive)
// Assumes srand() has already been called
int getRandomNumber(int min, int max)
{
	// static used for efficiency, so we only calculate this value once
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

	// evenly distribute the random number across our range														 
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void invalidInteger()
{
	std::cin.clear(); // put us back in 'normal' operation mode
	std::cin.ignore(32767, '\n'); // and remove the bad input
	std::cout << "Oops, that input is invalid. Please enter an integer between 1 and 100: ";
}

int checkForValidInt()
{
	while (1) // Loop until user enters a valid input
	{
		int x;
		std::cin >> x;

		// Check for failed extraction
		if (std::cin.fail()) // has a previous extraction failed?
		{
			// yep, so let's handle the failure
			invalidInteger();
		}
		else
		{
			std::cin.ignore(32767, '\n'); // remove any extraneous input

			if ((x >= 1) && (x <= 100))
			{
				return x;
			}
			else
			{
				std::cout << "Oops, that input is invalid. Please enter an integer between 1 and 100: ";
			}
		}
	}
}

bool playRound(int guess, int answer)
{
	cout << "Guess #" << guess << ": ";

	int number{ checkForValidInt() };

	if (number > answer)
	{
		cout << "Your guess is too high.\n";
		return false;
	}
	else if (number < answer)
	{
		cout << "Your guess is too low.\n";
		return false;
	}
	else
	{
		cout << "Correct! You win!\n";
		return true;
	}
}

void playLoop(int answer)
{
	int guess{ 1 };
	bool win{ false };
	cout << "Let's play a game. I'm thinking of a number. You have 7 tries to guess what it is.\n";
	while (!win)
	{
		if (guess > guesses)
		{
			cout << "Sorry, you lose. The correct number was " << answer << ".\n";
			break;
		}
		else
		{
			win = playRound(guess, answer);
			guess++;
		}
	}
	char input{ 'a' };
	while ((input != 'y') && (input != 'n'))
	{
		cout << "Would you like to play again (y/n)? ";
		cin >> input;
		std::cin.ignore(32767, '\n'); // remove any extraneous input
	}
	if (input == 'y')
	{
		playLoop(getRandomNumber(0, 100));
	}
	else
	{
		cout << "Thank you for playing.\n";
		exit(0);
	}
}

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	rand();	// Call rand() once to discard the first result.
	int number{ getRandomNumber(0, 100) };
	playLoop(number);
    return 0;
}

