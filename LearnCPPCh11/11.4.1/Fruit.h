#pragma once

#include <string>

using namespace std;

class Fruit
{
private:
	string m_name;
	string m_color;

public:
	Fruit(string name, string color);
	~Fruit();
	string getName() const;
	string getColor() const;
};

