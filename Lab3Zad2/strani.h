#ifndef _strani_h_
#define _strani_h_

#include"film.h"

enum typeOfTranslation {TITLOVAN,SINHRONIZOVAN};

class Strani:public Film{
public:

	Strani(string name, const Vreme& time,string country,typeOfTranslation type):Film(name,time),country(country),type(type){}
	char tag() const override { return 'S'; }

protected:

	void write(ostream& os)const override;

private:

	string country;
	typeOfTranslation type;

	static string strTypeOfTranslation[];
};

#endif _strani_h_
