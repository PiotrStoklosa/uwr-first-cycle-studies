#include <stdio.h>
#include <stdlib.h>
#include "wymierne.h"
int nwd(int a, int b)
{
    int c;
    while(b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
Wymierna konstruuj(int licznik,int mianownik)
{
    if (mianownik<0)
    {
        licznik*=(-1);
        mianownik*=(-1);
    }
    int znak=1;
    if (licznik<0)
    {
        znak=-1;
        licznik*=(-1);
    }
    int p=nwd(licznik, mianownik);
    licznik/=p;
    mianownik/=p;
    licznik*=znak;
    Wymierna x= licznik;
    x <<= 32;
    x |= mianownik;
    return x;
}
int licznik(Wymierna w)
{
    return w >> 32;
}
int mianownik (Wymierna w)
{
    w <<= 32;
    w >>=32;
    return w;
}
Wymierna wczytaj()
{
    int licznik,mianownik;
    scanf("%d/%d", &licznik, &mianownik);
    return konstruuj(licznik, mianownik);
}
void wypisz(Wymierna w)
{
    int licz=licznik(w);
    int miano=mianownik(w);
    printf("%d/", licz);
    printf("%d\n", miano);
}
Wymierna dod(Wymierna w, Wymierna r)
{
    int licz1=licznik(w);
    int mian1=mianownik(w);
    int licz2=licznik(r);
    int mian2=mianownik(r);
    int licz=(licz1*mian2 + licz2*mian1);
    int mian=(mian1*mian2);
    return konstruuj(licz,mian);
}
Wymierna ode(Wymierna w, Wymierna r)
{
    int licz1=licznik(w);
    int mian1=mianownik(w);
    int licz2=licznik(r);
    int mian2=mianownik(r);
    int licz=(licz1*mian2 - licz2*mian1);
    int mian=(mian1*mian2);
    return konstruuj(licz,mian);
}
Wymierna ilocz(Wymierna w, Wymierna r)
{
    int licz1=licznik(w);
    int mian1=mianownik(w);
    int licz2=licznik(r);
    int mian2=mianownik(r);
    int licz=(licz1*licz2);
    int mian=(mian1*mian2);
    return konstruuj(licz,mian);
}
Wymierna iloraz(Wymierna w, Wymierna r)
{
    int licz1=licznik(w);
    int mian1=mianownik(w);
    int licz2=licznik(r);
    int mian2=mianownik(r);
    int licz=(licz1*mian2);
    int mian=(mian1*licz2);
    return konstruuj(licz,mian);
}
