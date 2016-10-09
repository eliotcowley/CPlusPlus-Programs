#include "stdafx.h"
#include "Fraction.h"
#include <iostream>

using namespace std;

Fraction::Fraction(int numerator, int denominator)
	: m_numerator {numerator}, m_denominator {denominator}
{
	reduce();
}

Fraction::~Fraction()
{
}

void Fraction::print()
{
	cout << m_numerator << '/' << m_denominator << '\n';
}

Fraction operator*(Fraction & f1, Fraction & f2)
{
	return Fraction{ f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator };
}

Fraction operator*(Fraction & f, int i)
{
	return Fraction{ f.m_numerator * i, f.m_denominator };
}

Fraction operator*(int i, Fraction & f)
{
	return f * i;
}

int Fraction::gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

void Fraction::reduce()
{
	int divisor{ gcd(m_numerator, m_denominator) };
	m_numerator /= divisor;
	m_denominator /= divisor;
}
