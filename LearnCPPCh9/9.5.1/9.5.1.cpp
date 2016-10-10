/* 
	9.5.1.cpp : Implement overloaded operator+ for the Point class.
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

class Point
{
private:
	double m_x, m_y, m_z;

public:
	Point(double x = 0.0, double y = 0.0, double z = 0.0) :
		m_x(x), m_y(y), m_z(z)
	{
	}

	// Convert a Point into it's negative equivalent
	Point operator- () const;

	// Return true if the point is set at the origin
	bool operator! () const;

	Point operator+ () const;

	double getX() { return m_x; }
	double getY() { return m_y; }
	double getZ() { return m_z; }
};

// Convert a Point into its negative equivalent 
Point Point::operator- () const
{
	return Point(-m_x, -m_y, -m_z);
}

// Return true if the point is set at the origin, false otherwise
bool Point::operator! () const
{
	return (m_x == 0.0 && m_y == 0.0 && m_z == 0.0);
}

Point Point::operator+() const
{
	return *this;
}

int main()
{
	Point point{ -1.0, 2.0, -3.0 }; // use default constructor to set to (0.0, 0.0, 0.0)
	point = +point;
	cout << "Point: {" << point.getX() << ", " << point.getY() << ", " << point.getZ() << "}\n";

	return 0;
}

