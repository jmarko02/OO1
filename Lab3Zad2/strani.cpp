#include"strani.h"

string Strani::strTypeOfTranslation[] = { "TITLOVAN","SINHRONIZOVAN" };

void Strani::write(ostream& os) const
{
	Film::write(os);
	os << " " << country << " " << strTypeOfTranslation[type];
}
