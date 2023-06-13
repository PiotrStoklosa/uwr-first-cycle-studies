#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "zad2.h"
#include <string.h>
int main()
{
    char buf[][10]={"text1", "text2", "text3", "tekst4", "tekst5", "tekst6"};
    struct lista L,L2;
    printf("Tworzenie listy L\n");
    stworz(&L);
    printf("dodanie na poczatek listy L trzech slow\n");
    dodajpoczatek(&L, buf[0]);
    dodajpoczatek(&L, buf[1]);
    dodajpoczatek(&L, buf[2]);
    wypisz(&L);
    printf("Tworzenie listy L2\n");
    stworz(&L2);
    printf("dodanie na poczatek listy L2 trzech slow\n");
    dodajpoczatek(&L2, buf[3]);
    dodajpoczatek(&L2, buf[4]);
    dodajpoczatek(&L2, buf[5]);
    wypisz(&L2);
    printf("Skopiowanie listy L:\n");
    struct lista L3=skopiuj(&L);
    printf("Skopiowana lista L (L3):\n");
    wypisz(&L3);
    printf("Polaczenie dwoch list (L i L2)\n");
    sklej(&L,&L2);
    wypisz(&L);
    return 0;
}

