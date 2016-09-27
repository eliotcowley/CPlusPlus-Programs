/* 
	X.2.cpp : Write the following program: Create a struct that holds a student’s name and grade (on a scale of 0-100).
	Ask the user how many students they want to enter. Dynamically allocate an array to hold all of the students. Then
	prompt the user for each name and grade. Once the user has entered all the names and grades, sort the list by grade
	(highest first). Then print all the names and grades in sorted order.

	For the following input:

	Joe
	82
	Terry
	73
	Ralph
	4
	Alex
	94
	Mark
	88

	The output should look like this:

	Alex got a grade of 94
	Mark got a grade of 88
	Joe got a grade of 82
	Terry got a grade of 73
	Ralph got a grade of 4

	Hint: You can modify the selection sort algorithm from lesson 6.4 -- Sorting an array using selection sort to sort
	your dynamic array.
*/

#include "stdafx.h"
#include <string>
#include <iostream>
#include <utility>
using namespace std;

struct Student
{
	string name;
	int grade;
};

int main()
{
	// Get students and put into array
	cout << "How many students are there? ";
	int numStudents;
	cin >> numStudents;
	Student *students{ new Student[numStudents] };
	for (int i{ 0 }; i < numStudents; i++)
	{
		cout << "Enter the name of a student: ";
		string name;
		cin >> name;
		cout << "Enter their grade: ";
		int grade;
		cin >> grade;
		Student student{ name, grade };
		students[i] = student;
	}

	// Sort students by grade
	for (int startIndex = 0; startIndex < numStudents; ++startIndex)
	{
		int largestIndex = startIndex;

		for (int currentIndex = startIndex + 1; currentIndex < numStudents; ++currentIndex)
		{
			if (students[currentIndex].grade > students[largestIndex].grade)
				largestIndex = currentIndex;
		}

		swap(students[startIndex], students[largestIndex]);
	}

	// Print students
	for (int i{ 0 }; i < numStudents; i++)
	{
		cout << students[i].name << " got a grade of " << students[i].grade << ".\n";
	}

	delete[] students;
	
    return 0;
}

