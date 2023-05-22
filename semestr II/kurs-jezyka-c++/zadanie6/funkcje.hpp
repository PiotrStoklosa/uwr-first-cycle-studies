#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <utility>

using namespace std;

class Wyrazenie
{
public:
    virtual string opis() = 0;
    virtual double oblicz() = 0;
};
class Liczba : public Wyrazenie
{
    public:
        double wartosc;
        Liczba (double);
        string opis();
        double oblicz();
};
class Stala : public Wyrazenie
{
    protected:
        double wartosc;
};
class Pi : public Stala
{
public:
    string opis();
    double oblicz();
    Pi();
};
class E : public Stala
{
public:
    string opis();
    double oblicz();
    E();
};
class Fi : public Stala
{
public:
    string opis();
    double oblicz();
    Fi();
};
class Zmienna : public Wyrazenie
{
public:
    static vector<pair<string, double>> Zmienne;
    string Nazwa;
    void Dodaj_Zmienna(string, double);
    Zmienna(string);
    string opis();
    double oblicz();
};

class Operator1arg : public Wyrazenie
{
protected:
        Wyrazenie *wyr;
};
class Sin : public Operator1arg
{
public:
    Sin(Wyrazenie *);
    string opis();
    double oblicz();
};
class Cos : public Operator1arg
{
public:
    Cos(Wyrazenie *);
    string opis();
    double oblicz();
};
class Exp : public Operator1arg
{
public:
    Exp(Wyrazenie *);
    string opis();
    double oblicz();
};
class Ln : public Operator1arg
{
public:
    Ln(Wyrazenie *);
    string opis();
    double oblicz();
};
class Bezwzgl : public Operator1arg
{
public:
    Bezwzgl(Wyrazenie *);
    string opis();
    double oblicz();
};
class Przeciw : public Operator1arg
{
public:
    Przeciw(Wyrazenie *);
    string opis();
    double oblicz();
};
class Odwrot : public Operator1arg
{
public:
    Odwrot(Wyrazenie *);
    string opis();
    double oblicz();
};
class Operator2arg : public Operator1arg
{
protected:
      Wyrazenie *wyr2;
};
class Dodaj : public Operator2arg
{
public:
    Dodaj(Wyrazenie *, Wyrazenie *);
    string opis();
    double oblicz();
};
class Odejmij : public Operator2arg
{
public:
    Odejmij(Wyrazenie *, Wyrazenie *);
    string opis();
    double oblicz();
};
class Mnoz : public Operator2arg
{
public:
    Mnoz(Wyrazenie *, Wyrazenie *);
    string opis();
    double oblicz();
};
class Dziel : public Operator2arg
{
public:
    Dziel(Wyrazenie *, Wyrazenie *);
    string opis();
    double oblicz();
};
class Logarytm : public Operator2arg
{
public:
    Logarytm(Wyrazenie *, Wyrazenie *);
    string opis();
    double oblicz();
};
class Modulo : public Operator2arg
{
public:
    Modulo(Wyrazenie *, Wyrazenie *);
    string opis();
    double oblicz();
};
class Potega : public Operator2arg
{
public:
    Potega(Wyrazenie *, Wyrazenie *);
    string opis();
    double oblicz();
};
