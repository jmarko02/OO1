#ifndef _film_h_
#define _film_h_

#include<iostream>
using namespace std;
#include"Vreme.h"
#include"lista.h"

class Film {
public:
	Film(string n, const Vreme& t) :name(n), time(t) {}

	void rateFilm(int grade);
	Vreme getTime() const { return time; }
	double getAverageRating() const;

	virtual char tag() const = 0;
	virtual ~Film() {}

	friend ostream& operator<<(ostream& os, const Film& f);

private:
	string name;
	Vreme time;
	Lista<int> ratings;

protected:
	
	virtual void write(ostream& os)const;

};



#endif _film_h_
