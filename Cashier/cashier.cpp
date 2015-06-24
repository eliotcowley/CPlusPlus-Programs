/*
  	cashier.cpp
	Jun 24, 2015
	Eliot Cowley
*/

#include <iostream>
#include <iomanip>
using namespace std;

/* Ask the user for the cost of an item.
 * @return double
 */
double make_transaction();

/* Ask the user whether they would like to make another transaction.
 * @return bool
 */
bool decide();

/* Calculate the change to give back to the user, and print it to the console.
 */
void calculate_change(double);

double total = 0; // total cost

int main() {
	double cash;
	double change;

	total += make_transaction();
	while (decide()) {
		total += make_transaction();
	}
	cout << "Your total is $" << fixed << setprecision(2) << total << endl;
	cout << "Please enter the amount of money you will give to the cashier: ";
	cin >> cash;
	change = cash - total;
	cout << "Your change is $" << fixed << setprecision(2) << change << endl;
	calculate_change(change);

	return 0;
}

double make_transaction() {
	double cost;
	cout << "Please enter the price of your transaction: ";
	cin >> cost;
	return cost;
}

bool decide() {
	char decision;
	cout << "Would you like to make another transaction? (y/n) ";
	cin >> decision;
	if (decision == 'y') {
		return true;
	}
	return false;
}

void calculate_change(double change) {
	int dollars, quarters, dimes, nickels, pennies, coins;

	dollars = change;
	change *= 100;
	coins = change - dollars * 100;
	quarters = coins / 25;
	dimes = coins % 25 / 10;
	nickels = coins % 25 % 10 / 5;
	pennies = coins % 25 % 10 % 5;

	cout << "This amounts to " << dollars << (dollars != 1 ? " dollars, " : " dollar, ")
			<< quarters << (quarters != 1 ? " quarters, " : " quarter, ")
			<< dimes << (dimes != 1 ? " dimes, " : " dime, ")
			<< nickels << (nickels != 1 ? " nickels, and " : " nickel, and ")
			<< pennies << (pennies != 1 ? " pennies." : " penny.") << endl;
}
