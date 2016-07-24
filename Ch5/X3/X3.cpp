/* 
	X3.cpp : Time a loop. Write out the time in milliseconds. Do this for the default setting of your compiler and for a
	setting using an optimizer (e.g., -O2 or "release"). Be careful not to have the optimizer eliminate your whole loop as
	dead code because you did not use a result.
*/

#include "stdafx.h"
#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

int main()
{
	int i = 10;
	auto t1 = high_resolution_clock::now();
	while (i > 0)
	{
		i--;
		cout << i << "\n";
	}
	auto t2 = high_resolution_clock::now();
	cout << "Time passed: " << duration_cast<milliseconds>(t2 - t1).count() << " ms\n";
    return 0;
}

