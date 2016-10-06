#pragma once

class Point2d
{
private:
	double m_x;
	double m_y;

public:
	Point2d(double x = 0.0, double y = 0.0);
	~Point2d();
	void print();
	//double distanceTo(Point2d point);
	friend double distanceFrom(Point2d point1, Point2d point2);
};

