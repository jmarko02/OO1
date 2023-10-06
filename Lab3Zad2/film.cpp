#include "film.h"
#include"Vreme.h"


void Film::rateFilm(int grade)
{
    ratings += grade;
}

double Film::getAverageRating() const
{
    double sum = 0.0;
    for (int i = 0; i < ratings.getNumOfElem(); i++) {
        sum += ratings[i];
    }
    sum = sum / ratings.getNumOfElem();
    return sum;
}

void Film::write(ostream& os) const 
{
    os << tag() << " " << name << " " << getTime() << " " << getAverageRating();
}

ostream& operator<<(ostream& os, const Film& f)
{
    f.write(os);
    return os;
}
