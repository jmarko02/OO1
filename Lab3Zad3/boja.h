#ifndef _boja_h_
#define _boja_h_

#include <exception>
#include <iostream>


class GColor : public std::exception {
	const char* what() const override {
		return "Nemoguca vrednost boje! ";
	}
};

class Boja {
public:

	Boja(int r, int g, int b);

	friend bool operator==(const Boja& c1, const Boja& c2);

	friend bool operator!=(const Boja& c1, const Boja& c2);

	friend Boja operator+(const Boja& c1, const Boja& c2);

	friend std::ostream& operator<<(std::ostream& os, const Boja& c);

private:

	int red, green, blue;

};


#endif

