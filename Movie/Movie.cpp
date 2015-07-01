/*
 * Movie.cpp
 *
 *  Created on: Jul 1, 2015
 *      Author: Eliot Cowley
 */

#include "Movie.h"
#include <iostream>
using namespace std;

// constructors
Movie::Movie() {
	name = "Untitled";
	year = 2000;
	rating = "G";
}

Movie::Movie(string name, int year, string rating) {
	this->name = name;
	while (year < 1888 || year > 2015) { /* the first movie ever was made in 1888; 2015 is
	the year that this program was written */
		cout << "Sorry, that year is invalid. Please enter a valid year between "
				"1888 and 2015: ";
		cin >> year;
		cin.ignore();
	}
	this->year = year;
	this->rating = rating;
}

// destructor
Movie::~Movie() {

}

// getters
string Movie::getName() {
	return name;
}

int Movie::getYear() {
	return year;
}

string Movie::getRating() {
	return rating;
}

// setters
void Movie::setName(string name) {
	this->name = name;
}

void Movie::setYear(int year) {
	while (year < 1888 || year > 2015) { /* the first movie ever was made in 1888; 2015 is the
	year that this program was written */
		cout << "Sorry, that year is invalid. Please enter a valid year between "
				"1888 and 2015: ";
		cin >> year;
		cin.ignore();
	}
	this->year = year;
}

void Movie::setRating(string rating) {
	this->rating = rating;
}
