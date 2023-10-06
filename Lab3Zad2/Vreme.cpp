#include "Vreme.h"
#include<iomanip>

bool operator>(const Vreme& t1, const Vreme& t2)
{
    if (t1.hour > t2.hour) return true;
    else if (t1.hour == t2.hour) return t1.min > t2.min;
    else return false;
}

bool operator<(const Vreme& t1, const Vreme& t2)
{
    if (t1.hour < t2.hour) return true;
    else if (t1.hour == t2.hour) return t1.min < t2.min;
    else return false;
}

std::ostream& operator<<(std::ostream& os, const Vreme& t)
{
    return os << std::setw(2) << std::setfill('0') << t.hour << ":" <<std::setw(2) << std::setfill('0') << t.min ;
}

Vreme Vreme::operator+(const Vreme& t) const 
{
    int minutes = (min + t.min) / 60;
    int hours = hour + t.hour + minutes;
    int mins = (min + t.min)%60;
  
    return Vreme(hours, mins);

}
