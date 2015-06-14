/* loop_factorial
	Author: Eliot Cowley
	Date: 6/10/15
	Description: Factorial calculation using loops instead of recursion to conserve memory.
*/

#include <cstdio>
#include <iostream>
using namespace std;

unsigned long int factorial(unsigned long int n) {
	if (n < 2) {
		return 1;
	}
	unsigned long int total = 1;
	while (n > 2) {
		total *= n;
		n--;
	}
	return total;
}

int main(int argc, char ** argv) {
	unsigned long int n;
    /*n = 7;
    printf("Factorial of %ld is %ld\n", n, factorial(n));*/
	puts("Please enter a number you wish to know the factorial of:");
	cin >> n;
	cout << "The factorial of " << n << " is " << factorial(n);
    return 0;
}