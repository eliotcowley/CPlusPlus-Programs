// shared_ptr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <memory>

using namespace std;

#define ASSERT(expr) _ASSERT(expr);

int main()
{
	auto sp = shared_ptr<int>{};

	ASSERT(!sp);
	ASSERT(sp.use_count() == 0);
	ASSERT(!sp.unique());

	sp = make_shared<int>(123);

	ASSERT(sp);
	ASSERT(sp.use_count() == 1);
	ASSERT(sp.unique());

	auto sp2 = sp;

	ASSERT(sp.use_count() == 2);
	ASSERT(!sp.unique());

	ASSERT(sp2.use_count() == 2);
	ASSERT(!sp2.unique());

	int copy = *sp;

	int& ref = *sp;

	int* ptr = sp.get();

	ASSERT(sp.get() == sp2.get());
	ASSERT(sp == sp2);

    return 0;
}

