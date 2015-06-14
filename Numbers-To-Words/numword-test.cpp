// numword-test.cpp by Bill Weinman <http://bw.org/>

#include <cstdio>
#include <cstdint>
#include <string>
#include <iostream>
#include "numword.h"
using namespace std;

int main( int argc, char ** argv )
{
    bw::numword nw;
    uint64_t n;

    /*n = 3; cout << "n is " << n << ", " << nw.words(n) << "\n";
    n = 47; cout << "n is " << n << ", " << nw.words(n) << "\n";
    n = 73; cout << "n is " << n << ", " << nw.words(n) << "\n";
	n = 173; cout << "n is " << n << ", " << nw.words(n) << "\n";
    n = 1492; cout << "n is " << n << ", " << nw.words(n) << "\n";
    n = 10012; cout << "n is " << n << ", " << nw.words(n) << "\n";
    n = 100073; cout << "n is " << n << ", " << nw.words(n) << "\n";
    n = 1000000; cout << "n is " << n << ", " << nw.words(n) << "\n";
    n = 1000000001; cout << "n is " << n << ", " << nw.words(n) << "\n";
    n = 123000000000; cout << "n is " << n << ", " << nw.words(n) << "\n";
    n = 474142398123; cout << "n is " << n << ", " << nw.words(n) << "\n";
    n = 1474142398007; cout << "n is " << n << ", " << nw.words(n) << "\n";
    n = 999000000000000; cout << "n is " << n << ", " << nw.words(n) << "\n";
    n = 999999999999999999; cout << "n is " << n << ", " << nw.words(n) << "\n";
    n = 1000000000000000000; cout << "n is " << n << ", " << nw.words(n) << "\n";

    for( int i = 0; i < 201; ++i) {
		cout << i << " is " << nw.words(i) << "\n";
    }*/
	puts("Please enter an integer less than one quintillion.");
	cin >> n;
	cout << "You have entered " << nw.words(n);
    return 0;
}
