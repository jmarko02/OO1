#ifndef _Vreme_h_
#define _Vreme_h_
#include<iostream>
class Vreme {
private:
	int hour, min;

public:
	Vreme(int h, int m) { 
		hour = h;
		min = m;
	}

	friend bool operator>(const Vreme& t1, const Vreme& t2);

	friend bool operator<(const Vreme& t1, const Vreme& t2);

	Vreme operator+(const Vreme& t) const;

	friend std::ostream& operator<<(std::ostream& os, const Vreme& t);
};

#endif _Vreme_h
