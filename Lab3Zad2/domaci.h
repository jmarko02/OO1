#ifndef _domaci_h_
#define _domaci_h_

#include"film.h"
class Domaci : public Film {
public:
	Domaci(string name,const Vreme& time):Film(name,time) {}
	char tag() const override { return 'D'; }
}; 


#endif _domaci_h_

