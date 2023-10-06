#include "katren.h"

bool Katren::operator*() const
{
    return (numOfElem == 4 && verses[0] ^ verses[3] && verses[1] ^ verses[2]);
}
