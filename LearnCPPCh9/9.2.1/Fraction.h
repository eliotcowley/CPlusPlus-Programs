#pragma once

class Fraction
{
public:
	Fraction(int numerator, int denominator);
	~Fraction();
	void print();
	static int gcd(int a, int b);
	void reduce();
	friend Fraction operator*(Fraction &f1, Fraction &f2);
	friend Fraction operator*(Fraction &f, int i);
	friend Fraction operator*(int i, Fraction &f);

private:
	int m_numerator;
	int m_denominator;
};

