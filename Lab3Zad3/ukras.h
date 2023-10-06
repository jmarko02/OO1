#ifndef _ukras_h_
#define _ukras_h_

#include "boja.h"
#include<iostream>
using namespace std;

class Ukras {
public:
	Ukras(double mass, const Boja& color) :mass(mass), color(color) {}

	double getMass() { return mass; }
	Boja getColor() { return color; }

	friend ostream& operator<<(ostream& os, const Ukras& decoration) {
		decoration.write(os);
		return os;
	}

	virtual ~Ukras() {}

protected:
	virtual void write(ostream& os) const = 0;
	

private:
	double mass;
	Boja color;
};

#endif _ukras_h_
