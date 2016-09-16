/* 
	4.7.1.cpp : You are running a website, and you are trying to keep track of how much money you make per day from
	advertising. Declare an advertising struct that keeps track of how many ads you’ve shown to readers, what
	percentage of users clicked on ads, and how much you earned on average from each ad that was clicked. Read in
	values for each of these fields from the user. Pass the advertising struct to a function that prints each of the
	values, and then calculates how much you made for that day (multiply all 3 fields together).
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

struct Advertising
{
	int numAds;
	int percentClicked;
	int averageMoneyPerClick;
};

void printAdvertising(Advertising ad)
{
	cout << "Number of ads: " << ad.numAds << '\n';
	cout << "Percentage of ads clicked on: " << ad.percentClicked << '\n';
	cout << "Average money earned per click: " << ad.averageMoneyPerClick << '\n';
	cout << "Money made for this day: " << ad.numAds * (ad.percentClicked / 100) * ad.averageMoneyPerClick << '\n';
}

int main()
{
	Advertising ad{ 10, 10, 1 };
	printAdvertising(ad);

    return 0;
}

