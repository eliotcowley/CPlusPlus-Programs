#include "stdafx.h"
#include "Banana.h"

Banana::Banana(string name = "", string color = "")
	: Fruit(name, color)
{
}

Banana::~Banana()
{
}

ostream & operator<<(ostream & out, const Banana & banana)
{
	out << "Banana(" << banana.getName() << ", " << banana.getColor() << ")\n";
	return out;
}
