// X7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

void print_vector_of_ints(vector<int> v)
{
	for (int i : v)
	{
		cout << i << "\n";
	}
	cout << "\n";
}

int main()
{
	vector<int> v = { 5, 9, -1, 200, 0 };
	print_vector_of_ints(v);
	sort(v.begin(), v.end());
	print_vector_of_ints(v);

    return 0;
}

