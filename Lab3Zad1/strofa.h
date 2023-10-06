#ifndef _strofa_h_
#define _strofa_h_
#include "stih.h"
#include <exception>

class Strofa {
public:
	Strofa(int c);

	Strofa(const Strofa& s);
	Strofa(Strofa&& s);
	Strofa& operator=(const Strofa& s);
	Strofa& operator=(Strofa&& s);
	~Strofa();

	int operator+() const { return cap; }

	Strofa& operator+=(const Stih& verse);
	Strofa& operator-();
	Stih& operator[](int position);
	const Stih operator[](int position) const;
	Strofa& operator()(int i, int j);

	virtual bool operator*() const = 0;
	virtual char tag() const = 0;


	friend ostream& operator<<(ostream& os, const Strofa& s);

protected:

	int cap;
	Stih* verses;
	int numOfElem;

private:

	void copy(const Strofa& s);
	void move(Strofa& s);
	void clear();
};


#endif _strofa_h_

