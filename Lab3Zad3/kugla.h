#ifndef _kugla_h_
#define _kugla_h_

#include "ukras.h"

enum Dimension {MALA,SREDNJA,VELIKA,NAJVECA};

class Kugla : public Ukras {
public:
	Kugla(double mass,const Boja& color, Dimension size) :Ukras(mass, color), size(size){}

private:
	Dimension size;
	static string strDimensions[];

	void write(ostream& os) const override;
};

#endif _kugla_h_
