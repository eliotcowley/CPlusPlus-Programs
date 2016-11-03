#include "stdafx.h"
#include "Apple2.h"

Apple2::Apple2(string color = "red")
	: Fruit2{ "apple", color }
{
}

Apple2::Apple2(string name, string color = "red")
	: Fruit2{ name, color }
{
}

Apple2::~Apple2()
{
}
