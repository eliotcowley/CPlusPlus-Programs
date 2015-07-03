/*
average.cpp
Jul 3, 2015
Eliot Cowley
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main() {
	ifstream input;
	int errorcode = 1;
	try {
		input.open("numbers.txt", ios::in);
		if (input.fail()) {
			throw errorcode;
		}
	}
	catch (int error) {
		if (error == errorcode) {
			cout << "ERROR: File not found" << endl;
		}
	}
	cout << "Reading file..." << endl;
	int numRows = 0;
	double leftNum;
	double rightNum;
	double leftTotal;
	double rightTotal;
	while (!input.eof()) {
		input >> leftNum;
		leftTotal += leftNum;
		input >> rightNum;
		rightTotal += rightNum;
		numRows++;
	}
	cout << "Average of left column: " << leftTotal / numRows << endl;
	cout << "Average of right column: " << rightTotal / numRows << endl;
	return 0;
}
