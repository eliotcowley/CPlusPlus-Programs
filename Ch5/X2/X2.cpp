// X2.cpp : Write a program with two threads: one that writes hello every second and one that writes world! Every second.

#include "stdafx.h"
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
using namespace std::chrono;

mutex m;

void write_hello()
{
	unique_lock<mutex> lock{ m };
	cout << "hello";
	this_thread::sleep_for(seconds{ 1 });
}

void write_world()
{
	unique_lock<mutex> lock{ m };
	cout << "world!";
	this_thread::sleep_for(seconds{ 1 });
}

int main()
{
	mutex m;
	while (true)
	{
		thread t1{ write_hello };
		thread t2{ write_world };
		t1.join();
		t2.join();
	}
    return 0;
}

