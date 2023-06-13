#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "zad1.h"
#include <string.h>
int main()
{
    char buf[][10]={"text1", "text2", "text3", "tekst4"};
    struct lista L;
    printf("Tworzenie listy\n");
    stworz(&L);
    printf("Czy lista pusta?\n");
    bool x=pusta(&L);
    if (x)
        printf("Lista jest pusta\n");
    else
        printf("Lista nie jest pusta\n");
    printf("dodanie na poczatek listy dwoch slow\n");
    dodajpoczatek(&L, buf[0]);
    dodajpoczatek(&L, buf[1]);
    wypisz(&L);
    x=pusta(&L);
    printf("Czy lista pusta?\n");
    if (x)
        printf("Lista jest pusta\n");
    else
        printf("Lista nie jest pusta\n");
    printf("Dodanie na koniec listy slowa\n");
    dodajkoniec(&L, buf[2]);
    wypisz(&L);
    printf("dodanie na poczatek listy slowa\n");
    dodajpoczatek(&L, buf[3]);
    wypisz(&L);
    printf("Usuniecie slowa z poczatku\n");
    printf("Usuniete slowo:%s\n", usunpoczatek(&L));
    wypisz(&L);
    printf("Wartosc z poczatku listy:\n");
    printf("%s\n", poczatek(&L));
    printf("Dlugosc listy:\n");
    printf("%d \n", dlugosc(&L));
    return 0;
}
