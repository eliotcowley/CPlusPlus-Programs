#include "stdafx.h"
#include "Apple.h"

Apple::Apple(string name = "", string color = "", double fiber = 0.0)
	: Fruit(name, color), m_fiber {fiber}
{
}

Apple::~Apple()
{
}

ostream & operator<<(ostream & out, const Apple &apple)
{
	out << "Apple(" << apple.getName() << ", " << apple.getColor() << ", " << apple.m_fiber << ")\n";
	return out;
}
