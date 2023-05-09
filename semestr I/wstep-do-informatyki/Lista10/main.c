#include <stdio.h>
#include <stdlib.h>
struct elem{
    int val;
    struct elem *next;
};
struct elem *utworz(int wart)
{
    struct elem *nowa;
    nowa=malloc(sizeof(struct elem));
    nowa->val=wart;
    nowa->next=NULL;
    return nowa;
}
struct elem *usun(struct elem *lista)
{
    while(lista!=NULL)
        free(lista->next);
    return NULL;
}
void wypisz_dod(struct elem *lista)//1
{
    while(lista->next!=NULL)
    {
        if (lista->val>0)
            printf("%d ", lista->val);
        lista=lista->next;
    }
    if (lista->val>0)
        printf("%d\n", lista->val);
}
struct elem *dodaj_koniec(struct elem *lista, int wart)//2
{
    struct elem *poczatek=lista;
    struct elem *nastepny=utworz(wart);
    while(lista->next!=NULL)
        lista=lista->next;
    lista->next=nastepny;
    return poczatek;
}
struct elem *usun_pierwszy(struct elem *lista)
{
    if (lista!=NULL)
        return lista->next;
    return NULL;
}
struct elem *usun_ostatni(struct elem *lista)//3
{
    if (lista->next==NULL)
        return NULL;
    struct elem *poczatek=lista;
    while(lista->next->next!=NULL)
    {
        lista=lista->next;
    }
    free(lista->next);
    lista->next=NULL;
    return poczatek;
}
struct elem *polacz_listy(struct elem *lista1, struct elem *lista2)//4
{
    struct elem *poczatek=lista1;
    while(lista1->next!=NULL)
        lista1=lista1->next;
    lista1->next=lista2;
    return poczatek;
}
struct elem *usun_wart(struct elem *lista, int wart)//5
{
    while (lista->val==wart && lista!=NULL)
        lista=usun_pierwszy(lista);
    struct elem *poczatek=lista;
    if (lista==NULL)
        return NULL;
    while (lista->next!=NULL)
    {
        if (lista->next->val==wart)
        {
            if (lista->next->next==NULL)
            {
                free(lista->next);
                lista->next=NULL;
            }
            else
            {
                struct elem *pom;
                pom=lista->next;
                free(pom);
                lista->next=lista->next->next;
            }
        }
        lista=lista->next;
    }
    return poczatek;
}
void wypisz_od_konca(struct elem *lista)//6
{
    if (lista->next!=NULL)
        wypisz_od_konca(lista->next);
    printf("%d ", lista->val);
}
int dlugosc (struct elem *lista)
{
    int dl=1;
    if (lista==NULL)
        return 0;
    while(lista->next!=NULL)
    {
        dl++;
        lista=lista->next;
    }
    return dl;
}
struct elem *odwroc_liste(struct elem *lista)//7
{
    struct elem *nowa=utworz(0);
    struct elem *pocz=lista;
    while (pocz->next!=NULL)
    {
        while(lista->next!=NULL)
            lista=lista->next;
        dodaj_koniec(nowa,lista->val);
        lista=pocz;
        usun_ostatni(pocz);
    }
    dodaj_koniec(nowa,lista->val);
    usun_ostatni(pocz);
    usun_ostatni(lista);
    nowa=usun_pierwszy(nowa);
    return nowa;
}
void wypisz(struct elem *lista)
{
    if (lista==NULL)
        return;
    while(lista->next!=NULL)
    {
        printf("%d ", lista->val);
        lista=lista->next;
    }
    printf("%d\n", lista->val);
}
void rozdzielenie(struct elem *lista)//8
{
    struct elem *lista_dod=utworz(0);
    struct elem *lista_uje=utworz(0);
    while(lista!=NULL)
    {
        if (lista->val>0)
            lista_dod=dodaj_koniec(lista_dod, lista->val);
        else
            lista_uje=dodaj_koniec(lista_uje, lista->val);
        lista=usun_pierwszy(lista);
    }
    lista_dod=usun_pierwszy(lista_dod);
    lista_uje=usun_pierwszy(lista_uje);
    wypisz(lista_dod);
    wypisz(lista_uje);
}
struct elem2{//9a
    int val;
    struct elem2 *next;
    struct elem2 *previous;
};
struct elem2 *utworz2(int wart)//9b
{
    struct elem2 *nowa;
    nowa=malloc(sizeof(struct elem2));
    nowa->val=wart;
    nowa->next=NULL;
    nowa->previous=NULL;
    return nowa;
}
struct elem2 *dodaj_koniec2(struct elem2 *lista, int wart)//9c
{
    struct elem2 *poczatek=lista;
    struct elem2 *nastepny=utworz2(wart);
    if (lista==NULL)
        return nastepny;
    while(lista->next!=NULL)
        lista=lista->next;
    lista->next=nastepny;
    nastepny->previous=lista;
    return poczatek;
}
struct elem2 *usun_pierwszy2(struct elem2 *lista)//9d
{

    if (lista!=NULL && lista->next!=NULL)
    {
        lista->next->previous=NULL;
        return lista->next;
    }

    return NULL;
}
int main()
{
    struct elem *lista1=utworz(5);
    lista1 = dodaj_koniec(lista1, 27);
    lista1 = dodaj_koniec(lista1, 7);
    lista1 = dodaj_koniec(lista1, 15);
    lista1 = dodaj_koniec(lista1, 27);
    lista1 = dodaj_koniec(lista1, -27);
    lista1 = dodaj_koniec(lista1, 27);
    wypisz_dod(lista1);
    lista1 = usun_ostatni(lista1);
    wypisz(lista1);
    struct elem *lista2=utworz(8);
    lista2 = dodaj_koniec(lista2, 71);
    wypisz(lista2);
    lista1=polacz_listy(lista1,lista2);
    wypisz(lista1);
    usun_wart(lista1, 27);
    wypisz(lista1);
    wypisz_od_konca(lista1);
    printf("\n");
    wypisz(lista1);
    lista1=odwroc_liste(lista1);
    wypisz(lista1);
    rozdzielenie(lista1);
    return 0;
}
