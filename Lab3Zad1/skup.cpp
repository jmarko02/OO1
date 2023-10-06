#include "skup.h"

Skup& Skup::operator+=(const char c)
{
	for (auto i = myString.begin(); i < myString.end(); i++) {
		if (*i != c) myString += c;
	}
	return *this;
}

bool Skup::operator()(const char c) const
{
	for (auto i = myString.begin(); i < myString.end(); i++) {
		if (*i == c) return true;
	}
	return false;
}

