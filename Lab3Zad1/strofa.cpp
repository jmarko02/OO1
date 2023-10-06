#include "strofa.h"

void Strofa::copy(const Strofa& s)
{
    verses = new Stih[cap = s.cap];
    numOfElem = s.numOfElem;
    for (int i = 0; i < cap; i++) {
        verses[i] = s.verses[i];
    }
}

void Strofa::move(Strofa& s)
{
    verses = s.verses;
    cap = s.cap;
    numOfElem = s.numOfElem;
    s.verses = nullptr;
    s.cap = 0;
}

void Strofa::clear()
{
    delete[] verses;
    verses = nullptr;
}
Strofa::Strofa(int c)
{
    numOfElem = 0;
    cap = c;
    verses = new Stih[cap];
}
Strofa::Strofa(const Strofa& s)
{
    copy(s);
}
Strofa::Strofa(Strofa&& s)
{
    move(s);
}
Strofa& Strofa::operator=(const Strofa& s)
{
    if (this != &s) {
        clear();
        copy(s);
    }
    return *this;
}
Strofa& Strofa::operator=(Strofa&& s)
{
    if (this != &s) {
        clear();
        move(s);
    }
    return *this;
}
Strofa::~Strofa()
{
    clear();
}
Strofa& Strofa::operator+=(const Stih& verse)
{
    if (numOfElem == 0) verses[numOfElem++] = verse;
    else {
        if (numOfElem >= cap || (~verse != ~verses[0])) return *this;
        else {
            verses[numOfElem++] = verse;
        }
    }
    return *this;
}

Strofa& Strofa::operator-()
{
    numOfElem--;
    return *this;
}

Stih& Strofa::operator[](int position)
{
    if (position < 0 || position > numOfElem) throw GIndex();
    return verses[position];
}

const Stih Strofa::operator[](int position) const
{
    if (position < 0 || position > numOfElem) throw GIndex();
    return verses[position];
}

Strofa& Strofa::operator()(int i, int j)
{
    if (i < 0 || i > numOfElem-1 || j < 0 || j > numOfElem-1) throw GIndex();
    Stih current = verses[i];
    verses[i] = verses[j];
    verses[j] = current;
    return *this;

}

ostream& operator<<(ostream& os, const Strofa& s)
{
    for (int i = 0; i < s.numOfElem; i++) {
        os << s.verses[i] << endl;
    }
    return os;
}
