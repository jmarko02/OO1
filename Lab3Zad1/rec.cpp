#include "rec.h"
#include "skup.h"
#include <iostream>

Rec::Rec(string w)
{
	for (auto i = w.begin(); i < w.end(); i++) {
		if ((*i < 'A' || *i > 'Z') && (*i < 'a' || *i>'z')) continue;
		word += *i;
	}
}

int Rec::operator+() const
{
	return word.length();
}

int Rec::operator~() const
{
	Skup vowels("aeiouAEIOU");
	Skup sonants("lnrLNR");
	Skup sonants1("lnLN");
	int num = 0;

	if(vowels(*word.begin()) || ( sonants(*word.begin()) && !vowels(*(word.begin())+1) ) && (!sonants1(*word.begin()) || *word.begin() != 'j')) num++;

	for (auto i = word.begin()+1; i < word.end()-1; i++) {
		if (vowels(*i) || (sonants(*i) && !vowels(*(i - 1)) && !vowels(*(i + 1))) && (!sonants1(*i) || *(i+1) != 'j')) num++;
	}

	if (word.begin() != word.end() - 1 && (vowels(*(word.end() - 1)) || (sonants(*(word.end() - 1)) && !vowels(*(word.end() - 2))))) num++;

	return num;
}

int Rec::operator()(int n) const
{
	Skup vowels("aeiouAEIOU");
	Skup sonants("lnrLNR");
	if (n < 0) {
		n = ~(*this) + n;
	}
	int cnt = -1;
	int position = 0;
	if (vowels(*word.begin()) || (sonants(*word.begin()) && !vowels(*(word.begin()) + 1))) {
		cnt++;
		if (cnt == n) return position;
	}
	position++;

		
	for (auto i = word.begin() + 1; i < word.end() - 1; i++) {
		if (vowels(*i) || (sonants(*i) && !vowels(*(i - 1)) && !vowels(*(i + 1)))) {
			cnt++;
			if (cnt == n) return position;
				
		}
		position++;
	}

	if (vowels(*(word.end() - 1)) || (sonants(*(word.end() - 1)) && !vowels(*(word.end() - 2)))) {
		cnt++;
		if (cnt == n) return position;
	}
		
	return -1;


}

bool operator^(const Rec& word1, const Rec& word2)
{
	int position1;
	int position2;
	//cout << number1 << " " << number2;
	if (~(word1) == 1) {
		position1 = 0;
	}
	else {
		position1 = word1(-2);
	}
	if (~(word2) == 1) {
		position2 = 0;
	}
	else {
		position2 = word2(-2);
	}

	//cout << position1 << " " << position2 << endl;

	return word1.word.substr(position1) == word2.word.substr(position2);
}

istream& operator>>(istream& is,Rec& w)
{
	string str;
	is >> str;
	Rec newString(str);
	w = newString;

	//cin.clear();
	//cin.ignore(100, '\n');
	//cin.ignore(numeric_limits<streamsize>::max(), '\n');

	return is;
}

ostream& operator<<(ostream& os, const Rec& w)
{
	return os << w.word << " ";

}
