#pragma once

#include "Fruit.h"
#include <string>

using namespace std;

class Banana :
	public Fruit
{
public:
	Banana(string name, string color);
	~Banana();
	friend ostream & operator<<(ostream & out, const Banana & banana);
};

