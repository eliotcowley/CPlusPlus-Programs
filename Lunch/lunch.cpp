/*
	lunch.cpp
	Jul 2, 2015
	Eliot Cowley
*/

#include <iostream>
#include <cctype>
#include <iomanip>
using namespace std;

int numItems = 4;
string items[] = {"Hot Dog", "Hamburger", "French Fries", "Salad"};
int choice;
int quantity;
bool more;
char answer;
double costs[] = {2.50, 3.00, 2.00, 1.50};
double total = 0;

void chooseItem();
void chooseQuantity();
void chooseMore();

int main() {
	chooseItem();
	chooseQuantity();
	chooseMore();
	while (answer == 'y') {
		chooseItem();
		chooseQuantity();
		chooseMore();
	}
	cout << "Your total comes to $" << fixed << setprecision(2) << total << endl;
	cout << "Thank you, come again!" << endl;
	return 0;
}

// ask user for menu choice
void chooseItem() {
	cout << "What would you like for lunch? (Press the corresponding number key)" << endl;
	for (int i = 0; i < numItems; i++) {
		cout << i+1 << ". " << items[i] << ", $" << fixed << setprecision(2) << costs[i]
		     << endl;
	}
	cin >> choice;
	while (choice < 0 || choice > numItems) {
		cout << "Invalid choice. Please choose again." << endl;
		cin >> choice;
	}
}

// ask user for quantity of item
void chooseQuantity() {
	cout << "How many of this item would you like?" << endl;
	cin >> quantity;
	while (quantity <= 0) {
		cout << "Invalid amount. Please enter how many of this item you would like."
				<< endl;
		cin >> quantity;
	}
	total += costs[choice] * quantity;
}

// ask if user wants anything else
void chooseMore() {
	cout << "Would you like anything else? (y/n)" << endl;
	cin >> answer;
	answer = tolower(answer);
	while (answer != 'y' && answer != 'n') {
		cout << "Invalid choice. Please enter y or n." << endl;
		cin >> answer;
		answer = tolower(answer);
	}
}
