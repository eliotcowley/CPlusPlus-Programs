/* 
	8.x.1.cpp : Write a class named Point2d. Point2d should contain two member variables of type double: m_x, and m_y,
	both defaulted to 0.0. Provide a constructor and a print function.

	main should print:

	Point2d(0, 0);
	Point2d(3, 4);

	Now add a member function named distanceTo that takes another Point2d as a parameter, and calculates the distance
	between them. Given two points (x1, y1) and (x2, y2), the distance between them can be calculated as sqrt((x1 - x2)*
	(x1 - x2) + (y1 - y2)*(y1 - y2)). The sqrt function lives in header cmath.

	main should print:

	Point2d(0, 0);
	Point2d(3, 4);
	Distance between two points: 5

	Change function distanceTo from a member function to a non-member friend function that takes two Points as parameters.
	Also rename it “distanceFrom”.

	main should print:

	Point2d(0, 0);
	Point2d(3, 4);
	Distance between two points: 5
*/

#include "stdafx.h"
#include <iostream>
#include "Point2d.h"

double distanceFrom(Point2d point1, Point2d point2)
{
	return sqrt((point1.m_x - point2.m_x) * (point1.m_x - point2.m_x) 
		+ (point1.m_y - point2.m_y) * (point1.m_y - point2.m_y));
}

int main()
{
	Point2d first;
	Point2d second(3.0, 4.0);
	first.print();
	second.print();
	std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';

	return 0;
}

