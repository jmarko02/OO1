#ifndef _katren_h_
#define _katren_h_

#include "strofa.h"

class Katren : public Strofa {
public:
	Katren(int num = 4):Strofa(4){}

	char tag() const { return 'K';}
	bool operator*() const;
};


#endif _katren_h_
