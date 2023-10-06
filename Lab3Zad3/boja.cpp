#include "boja.h"

Boja::Boja(int r, int g, int b)
{
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) throw GColor();
	red = r;
	green = g;
	blue = b;
}

bool operator==(const Boja& c1, const Boja& c2)
{
	return (c1.blue == c2.blue && c1.green == c2.green && c1.red == c2.red);
}

bool operator!=(const Boja& c1, const Boja& c2)
{
	return (c1.blue != c2.blue || c1.green != c2.green || c1.red != c2.red);
}

Boja operator+(const Boja& c1, const Boja& c2)
{
	return Boja((c1.red + c2.red)/2, (c1.green + c2.green)/2, (c1.blue + c2.blue)/2);
}

std::ostream& operator<<(std::ostream& os, const Boja& c)
{
	return os << c.red << " " << c.green << " " << c.blue;
}

