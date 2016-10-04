// Header file that defines the Vector3d class

#pragma once

#include "Point3d.h" // for declaring Point3d::moveByVector() as a friend

class Vector3d
{
private:
	double m_x;
	double m_y;
	double m_z;

public:
	Vector3d(double x = 0.0, double y = 0.0, double z = 0.0);

	void print();
	friend void Point3d::moveByVector(Vector3d&);
};