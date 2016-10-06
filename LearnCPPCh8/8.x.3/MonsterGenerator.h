#pragma once

#include "Monster.h"

class MonsterGenerator
{
private:
	/*static string s_names[];
	static string s_roars[];*/

public:
	static Monster generateMonster();
	static int getRandomNumber(int min, int max);
};

