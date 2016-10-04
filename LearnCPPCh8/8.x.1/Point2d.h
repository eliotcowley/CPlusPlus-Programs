#pragma once

/* Point2d should contain two member variables of type double: m_x, and m_y, both defaulted to 0.0.
	Provide a constructor and a print function.

main should run.

This should print :

Point2d(0, 0);
Point2d(3, 4);
*/

class Point2d
{
private:
	double m_x;
	double m_y;

public:
	Point2d(double x = 0.0, double y = 0.0);
	~Point2d();
	void print();
};

