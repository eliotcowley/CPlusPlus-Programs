// X3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void send(int* to, int* from, int count)
{
	int n = (count + 7) / 8;
	switch (count % 8)
	{
	case 0: 
		do
		{
			*to++ = *from++;
	case 7: *to++ = *from++;
	case 6: *to++ = *from++;
	case 5: *to++ = *from++;
	case 4: *to++ = *from++;
	case 3: *to++ = *from++;
	case 2: *to++ = *from++;
	case 1: *to++ = *from++;
		} while (--n > 0);
	}
}

int main()
{
	int a{ 0 };
	int b{ 1 };
	int c{ 2 };
	send(&a, &b, c);
	cout << (2 % 8) << endl;
    return 0;
}

