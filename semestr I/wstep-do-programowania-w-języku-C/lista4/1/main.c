#include <stdio.h>
#include <stdlib.h>
#include "wymierne.h"
int main()
{
    Wymierna w1=wczytaj();
    Wymierna w2=wczytaj();
    printf("Pierwsza liczba: ");wypisz(w1);
    printf("Druga liczba: ");wypisz(w2);
    printf("Suma: ");wypisz(dod(w1, w2));
    printf("Roznica: ");wypisz(ode(w1, w2));
    printf("Iloczyn: ");wypisz(ilocz(w1, w2));
    printf("Iloraz: ");wypisz(iloraz(w1, w2));
    return 0;
}
