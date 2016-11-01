#include "stdafx.h"
#include "Fruit.h"

Fruit::Fruit(string name = "", string color = "")
	: m_name {name}, m_color {color}
{
}

Fruit::~Fruit()
{
}

string Fruit::getName() const
{
	return m_name;
}

string Fruit::getColor() const
{
	return m_color;
}
