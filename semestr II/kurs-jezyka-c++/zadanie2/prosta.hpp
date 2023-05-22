#include "wektor.hpp"
#include "punkt.hpp"
#ifndef PROSTA
#define PROSTA

class prosta{
private:
    double a;
    double b;
    double c;

public:
    prosta(punkt, punkt);
    prosta(wektor);
    prosta(double,double,double);
    prosta(prosta*,wektor);
    prosta();
    prosta(prosta&)=delete;

    double getA();
    double getB();
    double getC();

    bool czy_wektor_prostopadly(wektor);
    bool czy_wektor_rownolegly(wektor);
    bool czy_punkt_lezy_na_prostej(punkt);
};

bool czy_prostopadle(prosta*, prosta*);
bool czy_rownolegle(prosta*, prosta*);
void punkt_przeciecia_prostych(prosta*, prosta*);

#endif
