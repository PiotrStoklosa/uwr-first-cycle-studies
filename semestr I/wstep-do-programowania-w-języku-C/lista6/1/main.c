#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "kolejka.h"
double tab[100];
int main()
{
    kolejka k;
    printf("Inicjalizacja\n");
    inicjacjalizacja(k,5,tab);
    printf("\n");
    printf("Dopisanie liczby 3 na poczatek\n");
    dopisywaniepoczatek(k,3);
    wypisz(5,tab);
    printf("\n");
    printf("Dopisanie liczby 5 na poczatek\n");
    dopisywaniepoczatek(k,5);
    wypisz(5,tab);
    printf("\n");
    printf("Dopisanie liczby 8 na koniec\n");
    dopisywaniekoniec(k,8);
    wypisz(5,tab);
    printf("\n");
    printf("Pobranie liczby z poczatku\n");
    double d=pobieraniepoczatek(k);
    wypisz(5,tab);
    printf("Pobrana liczba: %lf\n", d);
    printf("\n");
    printf("Pobranie liczby z poczatku\n");
    d=pobieraniepoczatek(k);
    wypisz(5,tab);
    printf("Pobrana liczba: %lf\n", d);
    printf("\n");
    printf("Dopisanie liczby 2 na koniec\n");
    dopisywaniekoniec(k,2);
    wypisz(5,tab);
    printf("\n");
    printf("Pobranie liczby z konca\n");
    d=pobieraniekoniec(k);
    wypisz(5,tab);
    printf("Pobrana liczba: %lf\n", d);
    printf("\n");
    printf("Czy kolejka pusta?\n");
    if (pusta(k))
        printf("Tak\n");
    else
        printf("Nie\n");
    printf("\n");
    printf("Oproznianie kolejki\n");
    oproznianie(k,5,tab);
    wypisz(5,tab);
    printf("\n");
    printf("Czy kolejka pusta?\n");
    if (pusta(k))
        printf("Tak\n");
    else
        printf("Nie\n");
    return 0;
}
