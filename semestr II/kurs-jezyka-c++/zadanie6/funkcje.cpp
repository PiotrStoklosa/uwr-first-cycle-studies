#include "funkcje.hpp"

Liczba::Liczba (double val)
{
    this -> wartosc = val;
}
string Liczba::opis()
{
    return to_string(wartosc);
}
double Liczba::oblicz()
{
    return wartosc;
}

Pi::Pi ()
{
    this->wartosc = 3.1416;
}
string Pi::opis()
{
    return "pi";
}
double Pi::oblicz()
{
    return wartosc;
}

E::E ()
{
    this->wartosc = 2.7183;
}
string E::opis()
{
    return "e";
}
double E::oblicz()
{
    return wartosc;
}

Fi::Fi ()
{
    this->wartosc = 1.618;
}
string Fi::opis()
{
    return "fi";
}
double Fi::oblicz()
{
    return wartosc;
}

vector<pair<string, double>> Zmienna::Zmienne;

void Zmienna::Dodaj_Zmienna(string zmienna, double wartosc)
{
    auto x = make_pair(zmienna,wartosc);
    Zmienne.push_back(x);
}
string Zmienna::opis()
{
    return Nazwa;
}
Zmienna::Zmienna(string zmienna)
{
    Nazwa = zmienna;
}
double Zmienna::oblicz()
{
    for (unsigned int i=0; i<Zmienne.size(); i++)
        if (Zmienne[i].first==Nazwa)
        {
            return Zmienne[i].second;
        }
    cerr<<"Nie znalazlo takiej zmiennej!";
    return 0;
}
Sin::Sin (Wyrazenie *arg)
{
    this->wyr = arg;
}
string Sin::opis()
{
    return "Sin(" + wyr->opis() + ")";
}
double Sin::oblicz()
{
    return sin(wyr->oblicz());
}

Cos::Cos (Wyrazenie *arg)
{
    this->wyr = arg;
}
string Cos::opis()
{
    return "Cos(" + wyr->opis() + ")";
}
double Cos::oblicz()
{
    return cos(wyr->oblicz());
}

Bezwzgl::Bezwzgl (Wyrazenie *arg)
{
    this->wyr = arg;
}
string Bezwzgl::opis()
{
    return "|" + wyr->opis() + "|";
}
double Bezwzgl::oblicz()
{
    return abs(wyr->oblicz());
}

Przeciw::Przeciw (Wyrazenie *arg)
{
    this->wyr = arg;
}
string Przeciw::opis()
{
    return "-(" + wyr->opis() + ")";
}
double Przeciw::oblicz()
{
    return -1 * (wyr->oblicz());
}

Odwrot::Odwrot (Wyrazenie *arg)
{
    this->wyr = arg;
}
string Odwrot::opis()
{
    return "1/(" + wyr->opis() + ")";
}
double Odwrot::oblicz()
{
    return 1/(wyr->oblicz());
}

Ln::Ln (Wyrazenie *arg)
{
    this->wyr = arg;
}
string Ln::opis()
{
    return "ln(" + wyr->opis() + ")";
}
double Ln::oblicz()
{
    return log (wyr->oblicz());
}

Exp::Exp (Wyrazenie *arg)
{
    this->wyr = arg;
}
string Exp::opis()
{
    return "exp(" + wyr->opis() + ")";
}
double Exp::oblicz()
{
    return exp(wyr->oblicz());
}

Dodaj::Dodaj (Wyrazenie *arg1, Wyrazenie *arg2)
{
    this->wyr = arg1;
    this->wyr2 = arg2;
}
string Dodaj::opis()
{
    return wyr->opis() + " + " + wyr2->opis();
}
double Dodaj::oblicz()
{
    return wyr->oblicz() + wyr2->oblicz();
}

Odejmij::Odejmij (Wyrazenie *arg1, Wyrazenie *arg2)
{
    this->wyr = arg1;
    this->wyr2 = arg2;
}
string Odejmij::opis()
{
    return wyr->opis() + " - " + "(" + wyr2->opis() + ")";
}
double Odejmij::oblicz()
{
    return wyr->oblicz() - wyr2->oblicz();
}

Mnoz::Mnoz (Wyrazenie *arg1, Wyrazenie *arg2)
{
    this->wyr = arg1;
    this->wyr2 = arg2;
}
string Mnoz::opis()
{
    return "(" + wyr->opis() + ")" + " * " + "(" + wyr2->opis() + ")";
}
double Mnoz::oblicz()
{
    return wyr->oblicz() * wyr2->oblicz();
}

Dziel::Dziel (Wyrazenie *arg1, Wyrazenie *arg2)
{
    this->wyr = arg1;
    this->wyr2 = arg2;
}
string Dziel::opis()
{
     return "(" + wyr->opis() + ")" + " / " + "(" + wyr2->opis() + ")";
}
double Dziel::oblicz()
{
    return wyr->oblicz() / wyr2->oblicz();
}

Potega::Potega (Wyrazenie *arg1, Wyrazenie *arg2)
{
    this->wyr = arg1;
    this->wyr2 = arg2;
}
string Potega::opis()
{
    return "(" + wyr->opis() + ")" + " ^ " + "(" + wyr2->opis() + ")";
}
double Potega::oblicz()
{
    return pow(wyr->oblicz(), wyr2->oblicz());
}

Modulo::Modulo (Wyrazenie *arg1, Wyrazenie *arg2)
{
    this->wyr = arg1;
    this->wyr2 = arg2;
}
string Modulo::opis()
{
    return "(" + wyr->opis() + ")" + " % " + "(" + wyr2->opis() + ")";
}
double Modulo::oblicz()
{
    return fmod(wyr->oblicz(), wyr2->oblicz());
}

Logarytm::Logarytm (Wyrazenie *arg1, Wyrazenie *arg2)
{
    this->wyr = arg1;
    this->wyr2 = arg2;
}
string Logarytm::opis()
{
    return "log(" + wyr->opis() + " , " + wyr2->opis() + ")";
}
double Logarytm::oblicz()
{
    return log(wyr2->oblicz()) / log(wyr->oblicz());
}
