// X1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main()
{
	// While
	int i{ 0 };
	int max_length{ 10 };
	char input_line[10]{ 0 };
	int quest_count{ 0 };
	while (i != max_length)
	{
		if (input_line[i] == '?')
		{
			quest_count++;
		}
		i++;
	}

	// Pointer
	char* p{ input_line };
	while (i != max_length)
	{
		if (*p == '?')
		{
			quest_count++;
		}
		i++;
	}

	// Range-for
	for (char i : input_line)
	{
		if (i == '?')
		{
			quest_count++;
		}
	}

    return 0;
}

