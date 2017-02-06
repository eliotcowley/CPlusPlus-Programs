// SmartPointers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <memory>
#include <iostream>

using namespace std;

struct Hen
{
	unsigned id;
	float eggs;

	Hen(unsigned id_, float eggs_) :
		id{ id_ },
		eggs{ eggs_ }
	{
		cout << "Chicken soup!\n";
	}
};

auto GetHen() -> unique_ptr<Hen>
{
	return make_unique<Hen>(2, 3.9f);
}

auto UpdateHen(unique_ptr<Hen> hen) -> unique_ptr<Hen>
{
	hen->eggs += 1.8f;
	return hen;
}

int main()
{
	auto hen = GetHen();
	hen = UpdateHen(move(hen));
	cout << "eggs " << hen->eggs << '\n';

    return 0;
}

