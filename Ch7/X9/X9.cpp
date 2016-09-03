/* 
	X9.cpp : Define functions f(char), g(char&), and h(const char&). Call them with the arguments 'a', 49, 3300, c, uc,
	and sc, where c is a char, uc is an unsigned char, and sc is a signed char. Which calls are legal? Which calls cause
	the compiler to introduce a temporary variable?
*/

#include "stdafx.h"

void f(char c)
{

}

void g(char& cr)
{

}

void h(const char& ccr)
{

}

int main()
{
	f('a');
	g('a');
	h('a');

	f(49);
	g(49);
	h(49);

	f(3300);
	g(3300);
	h(3300);

	char c{ 'a' };
	f(c);
	g(c);
	h(c);

	unsigned char uc { 'a' };
	f(uc);
	g(uc);
	h(uc);

	signed char sc{ 'a' };
	f(sc);
	g(sc);
	h(sc);

    return 0;
}

