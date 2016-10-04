/* 
	8.x.1.cpp : Write a class named Point2d. Point2d should contain two member variables of type double: m_x, and m_y,
	both defaulted to 0.0. Provide a constructor and a print function.

	main should run.

	This should print:

	Point2d(0, 0);
	Point2d(3, 4);
*/

#include "stdafx.h"
#include <iostream>
#include "Point2d.h"

int main()
{
	Point2d first;
	Point2d second(3.0, 4.0);
	first.print();
	second.print();

	return 0;
}

