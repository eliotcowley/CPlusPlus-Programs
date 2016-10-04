#include "stdafx.h"
#include "Point2d.h"
#include <iostream>
using namespace std;

// Point2d should contain two member variables of type double: m_x, and m_y, both defaulted to 0.0.

Point2d::Point2d(double x, double y)
	: m_x {x}, m_y {y}
{

}

Point2d::~Point2d()
{

}

void Point2d::print()
{
	cout << "Point2d(" << m_x << ", " << m_y << ");\n";
}
