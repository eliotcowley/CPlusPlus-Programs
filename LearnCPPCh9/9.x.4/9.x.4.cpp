/* 
	9.x.4.cpp : Write a class named FixedPoint2 that implements the recommended solution from the previous question. Provide the overloaded operators
	and constructors required for main to run.

	And produce the result:

	34.56
	9.62
	5.01
	-5.01

	Hint: Although it may initially seem like more work initially, it's helpful to store both the non-fractional and fractional parts of the number with
	the same sign (e.g. both positive if the number is positive, and both negative if the number is negative). This makes doing math much easier later.

	Hint: Remember that int8_t is usually typedef'd as a char, so std::cout treats it accordingly.

	Hint: You can get the part of a double before the decimal by static casting the double to an integer.

	Hint: You can move a digit from the right of the decimal to the left of the decimal by multiplying by 10.

	Hint: You can round a number (on the left of the decimal) by using the round() function (included in header cmath).

	Overload operators >>, - (unary), + (binary) and the cast to double.

	main should run.

	And produce the output:

	true
	true
	true
	true
	true
	true
	true
	true
	34.56
	-34.56
	Enter a number: 5.678
	You entered: 5.68

	Hint: For operator>>, use your double constructor to create an anonymous object of type FixedPoint2, and assign it to your input object.
*/

#include "stdafx.h"
#include <cstdint>
#include <iostream>
#include <cmath>

using namespace std;

class FixedPoint2
{
private:
	int16_t m_wholeNum;
	int8_t m_decimal;

public:
	FixedPoint2(int16_t wholeNum = 0, int8_t decimal = 0) :
		m_wholeNum{ wholeNum }, m_decimal{ decimal }
	{
		
	}

	FixedPoint2(double d = 0)
	{
		// First we need to get the non-fractional component
		// We can do this by casting our double to an integer
		m_wholeNum = static_cast<int16_t>(d); // truncates fraction

		// Now we need to get the fractional component:
		// 1) d - m_base leaves only the fractional portion
		// 2) which can we multiply by 100 to move the digits to the left of the decimal
		// 3) then we can round this
		// 4) and finally static cast to an integer to drop any extra decimals
		m_decimal = static_cast<std::int8_t>(round((d - m_wholeNum) * 100));
	}

	friend FixedPoint2 operator+(const FixedPoint2 &fp1, const FixedPoint2 &fp2)
	{
		FixedPoint2 temp(fp1.m_wholeNum + fp2.m_wholeNum, fp1.m_decimal + fp2.m_decimal);
		// If our decimal is greater than 100, we've overflowed our decimal digit
		// we need to reduce the decimal and increase the base
		if (temp.m_decimal > 100)
		{
			temp.m_decimal -= 100;
			temp.m_wholeNum += 1;
		}
		// Else if our decimal is less than -100, we've overflowed our decimal digit in the negative direction
		// we need to increase the decimal and decrease the base
		else if (temp.m_decimal < -100)
		{
			temp.m_decimal += 100;
			temp.m_wholeNum -= 1;
		}

		return temp;
	}

	FixedPoint2 operator-()
	{
		return FixedPoint2(-m_wholeNum, -m_decimal);
	}

	operator double()
	{
		return m_wholeNum + static_cast<double>(m_decimal) / 100;
	}

	friend ostream& operator<<(ostream &out, const FixedPoint2 &fp2);
	friend istream& operator >> (istream &in, FixedPoint2 &fp2);
	//friend bool operator==(const FixedPoint2 &a, const FixedPoint2 &b);
};

ostream & operator<<(ostream & out, const FixedPoint2 &fp2)
{
	out << fp2.m_wholeNum << '.';
	if ((fp2.m_decimal < 10) && (fp2.m_decimal > -10))
	{
		out << '0';
	}
	out << static_cast<int>(fp2.m_decimal < 0 ? -fp2.m_decimal : fp2.m_decimal);
	return out;
}

istream & operator >> (istream & in, FixedPoint2 & fp2)
{
	double d;
	in >> d;
	fp2 = FixedPoint2{ d };
	return in;
}

void testAddition()
{
	// h/t to reader Sharjeel Safdar for this function
	std::cout << std::boolalpha;
	std::cout << (FixedPoint2(0.75) + FixedPoint2(1.23) == FixedPoint2(1.98)) << '\n'; // both positive, no decimal overflow
	std::cout << (FixedPoint2(0.75) + FixedPoint2(1.50) == FixedPoint2(2.25)) << '\n'; // both positive, with decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(-1.23) == FixedPoint2(-1.98)) << '\n'; // both negative, no decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(-1.50) == FixedPoint2(-2.25)) << '\n'; // both negative, with decimal overflow
	std::cout << (FixedPoint2(0.75) + FixedPoint2(-1.23) == FixedPoint2(-0.48)) << '\n'; // second negative, no decimal overflow
	std::cout << (FixedPoint2(0.75) + FixedPoint2(-1.50) == FixedPoint2(-0.75)) << '\n'; // second negative, possible decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(1.23) == FixedPoint2(0.48)) << '\n'; // first negative, no decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(1.50) == FixedPoint2(0.75)) << '\n'; // first negative, possible decimal overflow
}

int main()
{
	testAddition();

	FixedPoint2 a(34, 56);
	std::cout << a << '\n';

	std::cout << -a << '\n';

	std::cout << "Enter a number: "; // enter 5.678
	std::cin >> a;

	std::cout << "You entered: " << a << '\n';

	return 0;
}