#ifndef _skup_h_
#define _skup_h_
#include <string>
using namespace std;

class Skup {
public:
	Skup(string s) :myString(s) {}

	Skup(const Skup& s) = delete;
	Skup(Skup& s) = delete;

	Skup& operator+=(const char c);
	bool operator()(const char c)const;
	
private:
	string myString;
};


#endif _skup_h_
