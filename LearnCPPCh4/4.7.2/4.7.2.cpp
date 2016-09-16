/* 
	4.7.2.cpp : Create a struct to hold a fraction. The struct should have an integer numerator and an integer
	denominator member. Declare 2 fraction variables and read them in from the user. Write a function called multiply
	that takes both fractions, multiplies them together, and prints the result out as a decimal number. You do not need
	to reduce the fraction to its lowest terms.
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

struct Fraction
{
	int numerator;
	int denominator;
};

Fraction getFraction()
{
	int numerator, denominator;;
	cout << "Numerator: ";
	cin >> numerator;
	cout << "Denominator: ";
	cin >> denominator;
	Fraction f{ numerator, denominator };
	return f;
}

int main()
{
	cout << "Fraction 1\n";
	Fraction f1 = getFraction();
	cout << "Fraction 2\n";
	Fraction f2 = getFraction();
	int numerator{ f1.numerator * f2.numerator };
	int denominator{ f1.denominator * f2.denominator };
	cout << "The product of Fractions 1 and 2 is " << numerator << '/' << denominator << '\n';
	cout << "In decimal: " << (static_cast<float>(numerator) / static_cast<float>(denominator)) << '\n';
    return 0;
}

