/*
	movies.cpp
	Jul 1, 2015
	Eliot Cowley
*/

#include <iostream>
#include <string>
#include "Movie.h"
using namespace std;

int main() {
	int numMovies = 3;
	int maxChars = 50;
	Movie movies[numMovies];
	for (int i = 1; i <= numMovies; i++) {
		int date;
		char name[maxChars];
		char rating[maxChars];
		cout << "Please enter your #" << i << " favorite movie's title: " << endl;
		cin.getline(name, maxChars);
		movies[i-1].setName(name);
		cout << "Please enter the year of its release: " << endl;
		cin >> date;
		cin.ignore();
		movies[i-1].setYear(date);
		cout << "Please enter its rating (G, PG, PG-13, or R): " << endl;
		cin.getline(rating, maxChars);
		movies[i-1].setRating(rating);
	}
	cout << "Thank you! Now printing out a list of your top " << numMovies <<
			" favorite movies:" << endl << endl;
	for (int i = 1; i <= numMovies; i++) {
		cout << "Movie #" << i << ":" << endl;
		cout << "Title: " << movies[i-1].getName() << endl;
		cout << "Year: " << movies[i-1].getYear() << endl;
		cout << "Rating: " << movies[i-1].getRating() << endl << endl;
	}
	return 0;
}
