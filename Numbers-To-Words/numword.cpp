// Implementation of <numword.h>.

#include <stdio.h>
#include "numword.h"
#include <string>
using namespace bw;

// destructor
numword::~numword() {
	clearbuf();
}

// assignment operator
uint64_t numword::operator =(const uint64_t num) {
	setnum(num);
	return getnum();
}

string numword::words() {
	return words(_num);
}

// convert to words
string numword::words(const uint64_t num) {
	if (num > _BW_MAXNUM) {
		return errnum;
	}
	initbuf();
	uint64_t n = num;
	// zero
	if (n == 0) {
		appendbuf(_singles[0]);
		return _buf;
	}
	// powers
	if (n >= 1000) {
		for (int i = 5; i >= 1; i--) {
			int j = i;
			uint64_t power = 1000;
			while (j > 1) {
				power *= 1000;
				j--;
			}
			uint64_t temp = (n - (n % power)) / power;
			if (temp) {
				numword nw(temp);
				appendspace();
				appendbuf(nw.words());
				appendspace();
				appendbuf(_powers[i]);
				n -= temp * power;
			}
		}
	}
	// hundreds
	if ((n >= 100) && (n < 1000)) {
		uint64_t index = (n - (n % 100)) / 100;
		numword nw(index);
		appendspace();
		appendbuf(nw.words());
		appendspace();
		appendbuf(_hundred);
		n -= index * 100;
	}
	// tens
	if ((n >= 20) && (n <= 99)) {
		uint64_t index = (n - (n % 10)) / 10;
		appendspace();
		appendbuf(_tens[index]);
		n -= index * 10;
		hyphen_flag = true;
	}
	// teens
	if ((n > 9) && (n < 20)) {
		appendspace();
		appendbuf(_teens[n-10]);
		n = 0;
	}
	// singles
	if ((n > 0) && (n < 10)) {
		appendspace();
		appendbuf(_singles[n]);
	}
	return _buf;
}

void numword::clearbuf() {
	_buf = "";
	_buflen = 0;
}

void numword::initbuf() {
	clearbuf();
	hyphen_flag = false;
}

void numword::appendspace() {
	appendbuf( hyphen_flag ? _hyphen : _space);
	hyphen_flag = false;
}

void numword::appendbuf(const string s) {
	if (s.length() == 0) return;
    _buf += s;
}
