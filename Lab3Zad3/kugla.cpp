#include "kugla.h"

string Kugla::strDimensions[] = { "MALA","SREDNJA","VELIKA","NAJVECA" };

void Kugla::write(ostream& os) const
{
	switch (size) {
	case 0:
		os << '.'; break;
	case 1:
		os << 'o'; break;
	case 2:
		os << 'O'; break;
	case 3:
		os << "()"; break;
	}
}
