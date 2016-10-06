#include "stdafx.h"
#include "Point2d.h"
#include <iostream>
#include <cmath>
using namespace std;

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

//double Point2d::distanceTo(Point2d point)
//{
//	return sqrt((m_x - point.m_x) * (m_x - point.m_x) + (m_y - point.m_y) * (m_y - point.m_y));
//}
