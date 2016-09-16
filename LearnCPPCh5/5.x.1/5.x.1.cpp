/* 
	5.x.1.cpp : In the chapter 2 comprehensive quiz, we wrote a program to simulate a ball falling off of a tower. Because
	we didn’t have loops yet, the ball could only fall for 5 seconds.

	Take the program below and modify it so that the ball falls for as many seconds as needed until it reaches the ground.
*/

#include "stdafx.h"
#include <iostream>
#include "constants.h"

// gets initial height from user and returns it
double getInitialHeight()
{
	std::cout << "Enter the height of the tower in meters: ";
	double initialHeight;
	std::cin >> initialHeight;
	return initialHeight;
}

// Returns height from ground after "seconds" seconds
double calculateHeight(double initialHeight, int seconds)
{
	// Using formula: [ s = u * t + (a * t^2) / 2 ], here u(initial velocity) = 0
	double distanceFallen = (myConstants::gravity * seconds * seconds) / 2;
	double currentHeight = initialHeight - distanceFallen;

	return currentHeight;
}

// Prints height every second till ball has reached the ground
void printHeight(double height, int seconds)
{
	if (height > 0.0)
	{
		std::cout << "At " << seconds << " seconds, the ball is at height:\t" << height <<
			" meters\n";
	}
	else
		std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";
}

void calculateAndPrintHeight(double initialHeight, int seconds)
{
	double height = calculateHeight(initialHeight, seconds);
	printHeight(height, seconds);
}

int main()
{
	const double initialHeight = getInitialHeight();
	int seconds{ 0 };
	double currentHeight{ initialHeight };

	do
	{
		calculateAndPrintHeight(initialHeight, seconds);
		currentHeight = calculateHeight(initialHeight, seconds);
		seconds++;
	} while (currentHeight > 0.0);

	return 0;
}

