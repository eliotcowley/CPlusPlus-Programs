/*
 * Movie.h
 *
 *  Created on: Jul 1, 2015
 *      Author: Eliot Cowley
 */

#ifndef MOVIE_H_
#define MOVIE_H_
#include <string>
using namespace std;

class Movie {

private:
	// fields
	string name;
	int year;
	string rating;

public:
	// constructors
	Movie();
	Movie(string, int, string);

	// destructor
	virtual ~Movie();

	// getters
	string getName();
	int getYear();
	string getRating();

	// setters
	void setName(string);
	void setYear(int);
	void setRating(string);
};

#endif /* MOVIE_H_ */
