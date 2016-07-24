// X4.cpp : Repeat the histogram drawing example from 5.6.3 for a normal_distribution and 30 rows.

#include "stdafx.h"
#include <random>
#include <iostream>

using namespace std;

class rand_int
{
public:
	rand_int(int low, int high) :dist{low, high} {}
	int operator()() { return dist(re); }
private:
	default_random_engine re;
	normal_distribution<> dist;
};

int main()
{
	rand_int rnd{ 0, 29 };
	vector<int> histogram(30);
	for (int i = 0; i != 200; ++i)
	{
		++histogram[rnd()];
	}
	for (int i = 0; i != histogram.size(); ++i)
	{
		cout << i << '\t';
		for (int j = 0; j != histogram[i]; ++j)
		{
			cout << '*';
		}
		cout << endl;
	}
    return 0;
}

