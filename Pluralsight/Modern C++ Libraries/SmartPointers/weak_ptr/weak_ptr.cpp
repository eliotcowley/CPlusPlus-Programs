// weak_ptr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <memory>
#include <iostream>

using namespace std;

int main()
{
	auto sp = make_shared<int>(123);
	auto wp = weak_ptr<int>{sp};
	_ASSERT(!wp.expired());
	_ASSERT(wp.use_count() == 1);

	if (auto locked = wp.lock())
	{
		cout << "locked! " << *locked << '\n';
	}

	sp = nullptr;
	_ASSERT(wp.expired());
	_ASSERT(wp.use_count() == 0);

	if (auto locked = wp.lock())
	{
		cout << "locked! " << *locked << '\n';
	}
	else
	{
		wp.reset();
	}

    return 0;
}

