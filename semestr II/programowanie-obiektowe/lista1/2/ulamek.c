#include <stdio.h>
#include <stdlib.h>
#include "ulamki.h"
int nwd(int x, int y)
{
    if (y)
        return nwd(y,x%y);
    return x;
}
Ulamek *skroc(Ulamek *u)
{
    int znak;
    if (u->mianownik==0)
    {
        printf("Nie mozna dzielic przez 0!\n");
        return 0;
    }
    if (u->mianownik*u->licznik<0)
        znak=-1;
    else
        znak=1;
    u->mianownik=abs(u->mianownik);
    u->licznik=abs(u->licznik);
    int n=nwd(u->mianownik,u->licznik);
    u->mianownik/=n;
    u->licznik/=n;
    u->licznik*=znak;
    return u;
}
Ulamek *nowy_ulamek(int l, int m)
{

    Ulamek *u;
    u=malloc(sizeof(u));
    u->licznik=l;
    u->mianownik=m;
    return skroc(u);
}
Ulamek *dodaj(Ulamek *u1, Ulamek *u2)
{
    int x=(u1->licznik)*(u2->mianownik) + (u2->licznik)*(u1->mianownik);
    int y=u1->mianownik*u2->mianownik;
    return nowy_ulamek(x,y);
}
Ulamek *odejmij(Ulamek *u1, Ulamek *u2)
{
    int x=(u1->licznik)*(u2->mianownik) - (u2->licznik)*(u1->mianownik);
    int y=u1->mianownik*u2->mianownik;
    return nowy_ulamek(x,y);
}
Ulamek *pomnoz(Ulamek *u1, Ulamek *u2)
{
    int l=u1->licznik*u2->licznik;
    int m=u1->mianownik*u2->mianownik;
    return nowy_ulamek(l,m);
}
Ulamek *podziel(Ulamek *u1, Ulamek *u2)
{
    int l=u1->licznik*u2->mianownik;
    int m=u1->mianownik*u2->licznik;
    return nowy_ulamek(l,m);
}
Ulamek *dodaj2(Ulamek *u1, Ulamek *u2)
{
    u2->licznik=u1->licznik*u2->mianownik + u2->licznik*u1->mianownik;
    u2->mianownik=u1->mianownik*u2->mianownik;
    return skroc(u2);
}
Ulamek *odejmij2(Ulamek *u1, Ulamek *u2)
{
    u2->licznik=u1->licznik*u2->mianownik - u2->licznik*u1->mianownik;
    u2->mianownik=u1->mianownik*u2->mianownik;
    return skroc(u2);
}
Ulamek *pomnoz2(Ulamek *u1, Ulamek *u2)
{
    u2->licznik=u1->licznik*u2->licznik;
    u2->mianownik=u1->mianownik*u2->mianownik;
    return skroc(u2);
}
Ulamek *podziel2(Ulamek *u1, Ulamek *u2)
{
    int temp=u2->licznik;
    u2->licznik=u1->licznik*u2->mianownik;
    u2->mianownik=u1->mianownik*temp;
    return skroc(u2);
}
