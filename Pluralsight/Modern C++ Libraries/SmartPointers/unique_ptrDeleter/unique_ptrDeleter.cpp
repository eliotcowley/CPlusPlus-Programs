// unique_ptrDeleter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

int main()
{
	auto w = PTP_WORK
	{
		CreateThreadpoolWork([] (PTP_CALLBACK_INSTANCE, void*, PTP_WORK) {},
		nullptr,
		nullptr)
	};

	if (w)
	{
		SubmitThreadpoolWork(w);
	}

    return 0;
}

