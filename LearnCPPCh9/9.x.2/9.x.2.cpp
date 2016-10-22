/* 
	9.x.2.cpp : Write a class named Average that will keep track of the average of all integers passed to it. Use two members: The first one should be
	type int32_t, and used to keep track of the sum of all the numbers you’ve seen so far. The second should be of type int8_t, and used to keep track
	of how many numbers you’ve seen so far. You can divide them to find your average.

	main should produce the following result:

	4
	6
	12
	6.5
	7
	7

	Hint: Remember that int8_t is usually typedef'd as a char, so std::cout treats it accordingly.
*/

#include "stdafx.h"
#include <cstdint>
#include <iostream>

class Average 
{
private:
	int32_t m_sum;
	int8_t m_quantity;
public:
	Average();
	Average& operator+=(int rhs);
	friend std::ostream& operator<<(std::ostream &out, const Average &average);
};

Average::Average()
	: m_sum {0}, m_quantity {0}
{
}

Average& Average::operator+=(int rhs)
{
	m_sum += rhs;
	m_quantity++;
	return *this;
}

std::ostream & operator<<(std::ostream & out, const Average & average)
{
	out << static_cast<double>(average.m_sum) / average.m_quantity;
	//out << "\nSum: " << average.m_sum << " Quantity: " << static_cast<int>(average.m_quantity);
	return out;
}

int main()
{
	Average avg;

	avg += 4;
	std::cout << avg << '\n'; // 4 / 1 = 4

	avg += 8;
	std::cout << avg << '\n'; // (4 + 8) / 2 = 6

	avg += 24;
	std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

	avg += -10;
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

	Average copy = avg;
	std::cout << copy << '\n';

	return 0;
}