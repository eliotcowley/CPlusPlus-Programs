// Ch4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<string>
#include<iostream>

using namespace std;

int main()
{
	string name;
	int age;

	cout << "Please enter your name.\n";
	getline(cin, name);

	cout << "Please enter your age.\n";
	cin >> age;

	cout << "Your name is " << name << " and you are " << age << " years old.\n";

    return 0;
}

