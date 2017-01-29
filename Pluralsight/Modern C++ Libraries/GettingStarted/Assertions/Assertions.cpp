// Assertions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <crtdbg.h>
#include <stdio.h>
#include <Windows.h>

#define ASSERT _ASSERTE

#ifdef _DEBUG
#define VERIFY ASSERT
#else
#define VERIFY(expression) (expression)
#endif // _DEBUG

static_assert(sizeof(float) == 4, "Can't serialize floats!");

struct LastException
{
	DWORD result;

	LastException()
		: result{ GetLastError() }
	{

	}
};

struct ManualResetEvent
{
	HANDLE m_handle;

	ManualResetEvent()
	{
		m_handle = CreateEvent(nullptr, true, false, nullptr);

		if (!m_handle)
		{
			throw LastException();
		}
	}

	~ManualResetEvent()
	{
		VERIFY(CloseHandle(m_handle));
	}
};

int main()
{
	ASSERT(4 == 4);
	printf("Success!\n");

	auto e = ManualResetEvent{};
	auto e2 = e;
	
    return 0;
}

