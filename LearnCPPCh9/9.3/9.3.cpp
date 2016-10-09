/* 
	9.3.cpp : Take the Fraction class we wrote in the previous quiz (listed below) and add an overloaded operator<< and
	operator>> to it.

	And produce the result:

	Enter fraction 1: 2/3
	Enter fraction 2: 3/8
	2/3 * 3/8 is 1/4
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction(int numerator = 0, int denominator = 1) :
		m_numerator(numerator), m_denominator(denominator)
	{
		// We put reduce() in the constructor to ensure any fractions we make get reduced!
		// Since all of the overloaded operators create new Fractions, we can guarantee this will get called here
		reduce();
	}

	// We'll make gcd static so that it can be part of class Fraction without requiring an object of type Fraction to use
	static int gcd(int a, int b)
	{
		return b == 0 ? a : gcd(b, a % b);
	}

	void reduce()
	{
		int gcd = Fraction::gcd(m_numerator, m_denominator);
		m_numerator /= gcd;
		m_denominator /= gcd;
	}

	friend Fraction operator*(const Fraction &f1, const Fraction &f2);
	friend Fraction operator*(const Fraction &f1, int value);
	friend Fraction operator*(int value, const Fraction &f1);
	friend ostream& operator<<(ostream& out, const Fraction &f);
	friend istream& operator>> (istream& in, Fraction &f);

	void print()
	{
		std::cout << m_numerator << "/" << m_denominator << "\n";
	}
};

Fraction operator*(const Fraction &f1, const Fraction &f2)
{
	return Fraction(f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator);
}

Fraction operator*(const Fraction &f1, int value)
{
	return Fraction(f1.m_numerator * value, f1.m_denominator);
}

Fraction operator*(int value, const Fraction &f1)
{
	return Fraction(f1.m_numerator * value, f1.m_denominator);
}

ostream & operator<<(ostream & out, const Fraction & f)
{
	out << f.m_numerator << "/" << f.m_denominator;
	return out;
}

istream & operator >> (istream & in, Fraction & f)
{
	char c;

	in >> f.m_numerator;
	in >> c; // ignore the '/' separator
	in >> f.m_denominator;

	return in;
}

int main()
{
	Fraction f1;
	std::cout << "Enter fraction 1: ";
	std::cin >> f1;

	Fraction f2;
	std::cout << "Enter fraction 2: ";
	std::cin >> f2;

	std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n';

	return 0;
}

