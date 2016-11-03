#pragma once

#include <string>

using namespace std;

class Fruit2
{
public:
	Fruit2(string name, string color);
	~Fruit2();
	string getName();
	string getColor();
private:
	string m_name;
	string m_color;
};

