// X8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<vector>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

template<typename T>
void print_vector(vector<T> v)
{
	for (T t : v)
	{
		cout << t << "\n";
	}
	cout << "\n";
}

int main()
{
	vector<string> v = { "Kant", "Plato", "Aristotle", "Kierkegard", "Hume" };
	print_vector(v);
	sort(v.begin(), v.end());
	print_vector(v);

	return 0;
}

