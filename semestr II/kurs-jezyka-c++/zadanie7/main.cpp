#include "wymierne.hpp"

using namespace obliczenia;

int main()
{
    Wymierna a(-6, 4);
    Wymierna b(7, 3);
    Wymierna c = -a;
    Wymierna d = !a;

    cout<<"Stworzenie liczb: a(-3, 6); b(7, 3); c = -a; d= !a\n\n";
    cout<<"Zaokraglenie liczby c: "<<(int)c<<'\n';
    cout<<"Konwersja liczby b do double: "<<(double)b<<"\n\n";

    Wymierna suma = a+b;
    cout<<"Suma a + b: "<<"("<<suma.get_licz()<<"/" << suma.get_mian()<<")"<<'\n';

    Wymierna roznica = a-b;
    cout<<"Różnica a-b: "<<"("<<roznica.get_licz()<<"/" << roznica.get_mian()<<")"<<'\n';

    Wymierna iloczyn = a*b;
    cout<<"Iloczyn a*b: "<<"("<<iloczyn.get_licz()<<"/" << iloczyn.get_mian()<<")"<<'\n';

    Wymierna iloraz = a/b;
    cout<<"Iloraz a/b: "<<"("<<iloraz.get_licz()<<"/" << iloraz.get_mian()<<")"<<"\n\n";

    cout<<"Wyswietlenie ilorazu a/b dziesietnie: "<<iloraz<<"\n\n";

    cout<<"Liczba odwrotna do a: "<<d<<"\n\n";
    cout<<"Wyjatki:\n";
    cout<<"Dzielenie przez 0 (3,0): ";
    Wymierna dzielenieprzez0(3,0);

    Wymierna x(INT_MAX,1);
    Wymierna y(3,1);
    cout<<"\nPrzekroczony zakres (INT_MAX,1) + (3,1): ";
    Wymierna przekroczonyzakres = x+y;

    przekroczonyzakres = (1); // Zeby nie bylo warningu o nieuzywaniu zmiennej

    return 0;
}
