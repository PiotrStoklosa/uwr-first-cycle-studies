//Piotr Stoklosa

#include "funkcje.hpp"

int main()
{
    Zmienna *zm_x = new Zmienna("x");
    zm_x->Dodaj_Zmienna("x", 8);// x = 8
    Zmienna *zm_y = new Zmienna("y");
    zm_y->Dodaj_Zmienna("y", 10);// y = 10

    Wyrazenie *w1 = new Dziel(new Mnoz(new Odejmij(new Zmienna("x"), new Liczba(1)),new Zmienna("x")),new Liczba(2)); // ((x-1)*x)/2
    cout<<w1->opis()<<'\n';
    cout<<"Wynik dla x=8: "<<w1->oblicz()<<"\n\n";

    Wyrazenie *w2 = new Dziel(new Dodaj(new Liczba(3), new Liczba(5)),new Dodaj(new Liczba(2),new Mnoz(new Zmienna("x"), new Liczba(7)))); // (3+5)/(2+x*7)
    cout<<w2->opis()<<'\n';
    cout<<"Wynik dla x=8: "<<w2->oblicz()<<"\n\n";


    Wyrazenie *w3 = new Dodaj(new Liczba(2), new Odejmij(new Mnoz(new Zmienna("x"), new Liczba(7)), new Dodaj(new Mnoz(new Zmienna("y"), new Liczba(3)), new Liczba(5)))); // 2+x*7-(y*3+5)
    cout<<w3->opis()<<'\n';
    cout<<"Wynik dla x=8, y=10: "<<w3->oblicz()<<"\n\n";

    Wyrazenie *w4 = new Dziel(new Cos(new Mnoz(new Dodaj(new Zmienna("x"), new Liczba(1)), new Zmienna("x"))), new Exp(new Potega(new Zmienna("x"), new Liczba(2)))); // cos((x+1)*x)/e^x^2
    cout<<w4->opis()<<'\n';
    cout<<"Wynik dla x=8: "<<w4->oblicz()<<'\n';
}
