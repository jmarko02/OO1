#ifndef _rec_h_
#define _rec_h_
#include <string>
using namespace std;
#include "skup.h"
#include <limits>
#include <iostream>

class Rec {
public:
	Rec(string w);

	int operator+() const;
	int operator~() const;
	int operator()(int n) const;

	friend bool operator^(const Rec& word1, const Rec& word2);
	friend istream& operator>>(istream& is,Rec& word);
	friend ostream& operator<<(ostream& os, const Rec& word);
private:
	string word;
};

#endif _rec_h_

