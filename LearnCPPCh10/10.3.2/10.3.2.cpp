/*
	10.3.2.cpp : Update the Teacher/Dept example so the Dept can handle multiple Teachers. The following code should execute:

	This should print:

	Department: Bob Frank Beth
	Bob still exists!
	Frank still exists!
	Beth still exists!

	Hint: Use a std::vector to hold the teachers. Use the std::vector::push_back() to add Teachers. Use the std::vector::size() to get the length of the
	std::vector for printing.
*/

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Teacher
{
private:
	string m_name;

public:
	Teacher(string name):
		m_name {name}
	{

	}

	string getName()
	{
		return m_name;
	}
};

class Department
{
private:
	vector<Teacher*> teachers;

public:
	void add(Teacher *t)
	{
		teachers.push_back(t);
	}

	friend ostream& operator<<(ostream& out, const Department &d);
};

ostream & operator<<(ostream & out, const Department &d)
{
	out << "Department: ";
	for (int i{ 0 }; i < d.teachers.size(); i++)
	{
		out << d.teachers[i]->getName() << ' ';
	}
	out << '\n';
	return out;
}

int main()
{
	// Create a teacher outside the scope of the Department
	Teacher *t1 = new Teacher("Bob"); // create a teacher
	Teacher *t2 = new Teacher("Frank");
	Teacher *t3 = new Teacher("Beth");

	{
		// Create a department and use the constructor parameter to pass
		// the teacher to it.
		Department dept; // create an empty Department
		dept.add(t1);
		dept.add(t2);
		dept.add(t3);

		std::cout << dept;

	} // dept goes out of scope here and is destroyed

	std::cout << t1->getName() << " still exists!\n";
	std::cout << t2->getName() << " still exists!\n";
	std::cout << t3->getName() << " still exists!\n";

	delete t1;
	delete t2;
	delete t3;

	return 0;
}