// Member functions of the Point3d class defined here

#include "stdafx.h"
#include <iostream> // for std::cout
#include "Point3d.h" // Point3d class declared in this
#include "Vector3d.h" // for the parameter of the function moveByVector()

Point3d::Point3d(double x, double y, double z) : m_x(x), m_y(y), m_z(z) {}

void Point3d::moveByVector(Vector3d &v)
{
	// Add the vector components to the corresponding point coordinates
	m_x += v.m_x;
	m_y += v.m_y;
	m_z += v.m_z;
}

void Point3d::print()
{
	std::cout << "Point(" << m_x << " , " << m_y << " , " << m_z << ")\n";
}