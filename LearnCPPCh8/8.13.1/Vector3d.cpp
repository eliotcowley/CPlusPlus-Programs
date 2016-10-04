// Member functions of the Vector3d class defined here

#include "stdafx.h"
#include <iostream>
#include "Vector3d.h" // Vector3d class declared in this file

Vector3d::Vector3d(double x, double y, double z) : m_x(x), m_y(y), m_z(z) {}

void Vector3d::print()
{
	std::cout << "Vector(" << m_x << " , " << m_y << " , " << m_z << ")\n";
}