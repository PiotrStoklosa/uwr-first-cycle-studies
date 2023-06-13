#include <stdio.h>
#include <stdlib.h>
typedef struct ulamek{
int licznik;
int mianownik;
}Ulamek;
int nwd(int x, int y);
Ulamek *skroc(Ulamek *u);
Ulamek *nowy_ulamek(int l, int m);
Ulamek *dodaj(Ulamek *u1, Ulamek *u2);
Ulamek *odejmij(Ulamek *u1, Ulamek *u2);
Ulamek *pomnoz(Ulamek *u1, Ulamek *u2);
Ulamek *podziel(Ulamek *u1, Ulamek *u2);
Ulamek *dodaj2(Ulamek *u1, Ulamek *u2);
Ulamek *odejmij2(Ulamek *u1, Ulamek *u2);
Ulamek *pomnoz2(Ulamek *u1, Ulamek *u2);
Ulamek *podziel2(Ulamek *u1, Ulamek *u2);

