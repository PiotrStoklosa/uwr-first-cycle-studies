// Piotr Stoklosa Zadanie2
#include <iostream>
#include "prosta.hpp"
#include "wektor.hpp"
#include "punkt.hpp"

using namespace std;

int main()
{
    cout<<"Testowanie wektorow:\n\n\n";


    cout<<"Tworzenie dwoch wektorow o wspolrzednych v1(5,7) i v2(8,9)\n";
    wektor v1(5,7);
    wektor v2(8,9);

    wektor v3=(v2);
    cout<<"Wspolrzedne skopiowanego wektora v2: "<<v3.dx<<" "<<v3.dy<<'\n';

    wektor v4(skladanie(v1,v2).dx, skladanie(v1,v2).dy);
    cout<<"Wspolrzedne zlozonego wektora v1 z v2: "<<v4.dx<<" "<<v4.dy<<"\n\n";


    cout<<"Testowanie punktow:\n\n\n";


    cout<<"Tworzenie dwoch punktow o wspolrzedych p1(2,6) i p2(4,8.8)\n";
    punkt p1(2,6);
    punkt p2(4,8.8);

    punkt p3(p1,v1);
    cout<<"Wspolrzedne przesunietego punktu p1 o wektor v1: ";
    cout<<p3.x<<" "<<p3.y<<"\n\n";


    cout<<"Testowanie prostej:\n\n\n";


    prosta prosta1( 1, 1, 1);
    prosta prosta2( 1, 1, 2);
    prosta prosta3( 6, 1, 2);
    cout<<"Tworzenie trzech prostych o wspolczynnikach prosta1(1,1,1), prosta2(1,1,2) i prosta3(6,1,2)\n\n";

    cout<<"Czy prosta1 jest prostopadla do prostej2: "<<czy_prostopadle(&prosta1,&prosta2)<<"\n";

    cout<<"Czy prosta1 jest rownolegla do prostej2: "<<czy_rownolegle(&prosta1,&prosta2)<<"\n\n";

    cout<<"Punkt przeciecia prostych prosta1, prosta2: ";
    punkt_przeciecia_prostych(&prosta1, &prosta2);

    cout<<"\nPunkt przeciecia prostych prosta1, prosta3: ";
    punkt_przeciecia_prostych(&prosta1, &prosta3);

    cout<<"\nCzy punkt p3 lezy na prostej prosta1 (oraz ewentualna odleglosc wyswietlona jako pierwsza): ";
    cout<<prosta1.czy_punkt_lezy_na_prostej(p3);

    cout<<"\n\nCzy prosta prosta1 jest prostopadla do wektora v1: "<<prosta1.czy_wektor_prostopadly(v1)<<'\n';

    cout<<"Czy prosta prosta1 jest rownolegla do wektora v1: "<<prosta1.czy_wektor_rownolegly(v1)<<'\n';

    cout<<"\nWspolczynniki prostej utworzonej z punktow p1,p2 (w postaci unormowanej): ";
    prosta prostazpkt(p1,p2);
    cout<<prostazpkt.getA()<<" "<<prostazpkt.getB()<<" "<<prostazpkt.getC()<<" \n";

    cout<<"\nWspolczynniki prostej prostazpkt przesunietej o wektor v2 (prostej utworzonej z punktow p1,p2): ";
    prosta przesuniecie(&prostazpkt,v2);
    cout<<przesuniecie.getA()<<" "<<przesuniecie.getB()<<" "<<przesuniecie.getC()<<"\n\n";

    cout<<"Utworzenie prostej prostazwektora prostopadlej do wektora v3, przechodzacej przez punkt oddalony od początku układu współrzędnych przez v3 i wypisanie jej wspolczynnikow: ";
    prosta prostazwektora(v3);
    cout<<prostazwektora.getA()<<" "<<prostazwektora.getB()<<" "<<prostazwektora.getC()<<"\n";

    return 0;
}
