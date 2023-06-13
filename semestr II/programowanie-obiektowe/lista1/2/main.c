#include <stdio.h>
#include <stdlib.h>
#include "ulamki.h"
int main()
{
    Ulamek *n;
    Ulamek *p;
    n=nowy_ulamek(13,35);
    p=nowy_ulamek(4,-70);
    Ulamek *u;

    printf("Wyswietl licznik i mianownik ulamkow 13/35 oraz 4/-70:\n%d/%d\n%d/%d\n\n", n->licznik, n->mianownik, p->licznik, p->mianownik);
    printf("1 realizacja z utworzeniem nowego ulamka.\n\n%d/%d + %d/%d = ", n->licznik, n->mianownik, p->licznik, p->mianownik);
    u=dodaj(n,p);
    printf("%d/%d\n\n",u->licznik, u->mianownik);

    printf("%d/%d - %d/%d = ", n->licznik, n->mianownik, p->licznik, p->mianownik);
    u=odejmij(n,p);
    printf("%d/%d\n\n",u->licznik, u->mianownik);

    printf("%d/%d * %d/%d = ", n->licznik, n->mianownik, p->licznik, p->mianownik);
    u=pomnoz(n,p);
    printf("%d/%d\n\n",u->licznik, u->mianownik);

    printf("%d/%d / %d/%d = ", n->licznik, n->mianownik, p->licznik, p->mianownik);
    u=podziel(n,p);
    printf("%d/%d\n\n",u->licznik, u->mianownik);


    printf("2 realizacja z nadpisywaniem drugiego ulamka.\n\n%d/%d + %d/%d = ", n->licznik, n->mianownik, p->licznik, p->mianownik);
    u=dodaj2(n,p);
    printf("%d/%d\n\n",u->licznik, u->mianownik);

    printf("%d/%d - %d/%d = ", n->licznik, n->mianownik, p->licznik, p->mianownik);
    u=odejmij2(n,p);
    printf("%d/%d\n\n",u->licznik, u->mianownik);

    printf("%d/%d * %d/%d = ", n->licznik, n->mianownik, p->licznik, p->mianownik);
    u=pomnoz2(n,p);
    printf("%d/%d\n\n",u->licznik, u->mianownik);

    printf("%d/%d / %d/%d = ", n->licznik, n->mianownik, p->licznik, p->mianownik);
    u=podziel2(n,p);
    printf("%d/%d\n\n",u->licznik, u->mianownik);

    printf("Kiedy probuje dzielic przez 0 (np. 1/2 / 0/7)\n");
    n=nowy_ulamek(1,2);
    p=nowy_ulamek(0,7);
    u=podziel(n,p);

    printf("\nKiedy probuje stworzyc ulamek majacy 0 w mianowniku (np. 1/0)\n");
    n=nowy_ulamek(1,0);

    return 0;
}
