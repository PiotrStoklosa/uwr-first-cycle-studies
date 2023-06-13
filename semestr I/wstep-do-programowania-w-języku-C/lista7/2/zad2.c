#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "zad2.h"
void stworz(struct lista *l)
{
    l->pierwszy=NULL;
    l->ostatni=NULL;
}
struct element *dodajpoczatek(struct lista *l, char *tekst)
{
    struct element *p;
    p=malloc(sizeof(struct element));
    p->napis=tekst;
    if (l->ostatni==NULL)
    {
        l->ostatni=p;
        p->next=p;
    }
    else
    {
        p->next = l->pierwszy;
        l->ostatni->next=p;
    }
    l->pierwszy=p;
    return p;
}
struct element *dodajkoniec(struct lista *l, char *tekst)
{
    struct element *p;
    p=malloc(sizeof(struct element));
    p->napis=tekst;
    if (l->ostatni==NULL)
    {
        l->pierwszy=p;
        p->next=p;
    }
    else
    {
        l->ostatni->next=p;
        p->next=l->pierwszy;
    }
    l->ostatni=p;
    return p;
}
char *poczatek(struct lista *l)
{
    if (l->pierwszy==NULL)
        return NULL;
    return l->pierwszy->napis;
}
char *usunpoczatek(struct lista *l)
{
    if (l->pierwszy==NULL)
        return NULL;
    char *tmp=poczatek(l);
    if (l->pierwszy->next==l->pierwszy)
    {
        free(l->pierwszy);
        l->pierwszy=NULL;
        l->ostatni=NULL;
    }
    else
    {
        l->ostatni->next=l->pierwszy->next;
        struct element *o=l->pierwszy;
        l->pierwszy=l->pierwszy->next;
        free(o);

    }
    return tmp;
}
bool pusta(struct lista *l)
{
    return (l->pierwszy==NULL);
}
int dlugosc(struct lista *l)
{
    long long int dl=1;
    if (pusta(l))
        return 0;
    struct element *x=l->pierwszy;
    while(x!=l->ostatni)
    {
        dl++;
        x=x->next;
    }
    return dl;
}
void wypisz(struct lista *l)
{
    printf("%s ", l->pierwszy->napis);
    for(struct element *i = l->pierwszy->next; i!=l->pierwszy; i=i->next)
    {
        printf("%s ", i->napis);
    }
    printf("\n");
}
void sklej(struct lista *a, struct lista *b)
{
    a->ostatni->next=b->pierwszy;
    b->ostatni->next=a->pierwszy;
    a->ostatni=b->ostatni;
    b->pierwszy=NULL;
    b->ostatni=NULL;
}
struct lista skopiuj(struct lista *l)
{
    struct lista wynik;
    stworz(&wynik);
    dodajkoniec(&wynik,l->pierwszy->napis);
    for(struct element *i = l->pierwszy->next; i!=l->pierwszy; i=i->next)
        dodajkoniec(&wynik,i->napis);
    return wynik;
}
