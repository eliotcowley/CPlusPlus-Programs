/* 
	9.2.1.cpp : Write a class named Fraction that has a integer numerator and denominator member. Write a print() function
	that prints out the fraction.

	Add overloaded multiplication operators to handle multiplication between a Fraction and integer, and between two
	Fractions. Use the friend function method.

	Hint: To multiply two fractions, fist multiply the two numerators together, and then multiply the two denominators
	together. To multiply a fraction and an integer, multiply the numerator of the fraction by the integer and leave the
	denominator alone.

	Extra credit: the fraction 2/4 is the same as 1/2, but 2/4 is not reduced to the lowest terms. We can reduce any given
	fraction to lowest terms by finding the greatest common divisor (GCD) between the numerator and denominator, and then
	dividing both the numerator and denominator by the GCD.

	Add this function to your class, and write a member function named reduce() that reduces your fraction. Make sure all
	fractions are properly reduced.
*/

#include "stdafx.h"
#include "Fraction.h"

int main()
{
	Fraction f1(2, 5);
	f1.print();

	Fraction f2(3, 8);
	f2.print();

	Fraction f3 = f1 * f2;
	f3.print();

	Fraction f4 = f1 * 2;
	f4.print();

	Fraction f5 = 2 * f2;
	f5.print();

	Fraction f6 = Fraction(1, 2) * Fraction(2, 3) * Fraction(3, 4);
	f6.print();

	return 0;
}

