#pragma once

#include "Fruit2.h"
#include <string>

using namespace std;

class Apple2 :
	public Fruit2
{
public:
	Apple2(string color);
	Apple2(string name, string color);
	~Apple2();
};

