#pragma once

#include "Fruit.h"

class Apple :
	public Fruit
{
private:
	double m_fiber;

public:
	Apple(string name, string color, double fiber);
	~Apple();
	friend ostream& operator<<(ostream & out, const Apple &apple);
};

