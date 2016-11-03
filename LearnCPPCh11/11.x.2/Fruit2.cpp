#include "stdafx.h"
#include "Fruit2.h"

Fruit2::Fruit2(string name = "", string color = "")
	: m_name {name}, m_color {color}
{
}

Fruit2::~Fruit2()
{
}

string Fruit2::getName()
{
	return m_name;
}

string Fruit2::getColor()
{
	return m_color;
}
