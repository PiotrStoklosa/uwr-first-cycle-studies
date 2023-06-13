#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "kolejka.h"
bool pelna(kolejka k)
{
    return k[1]-k[2]==1 || (k[1]==k[0] && k[2]==k[3]-1);
}
bool pusta(kolejka k)
{
    return k[2]==k[1];
}
void inicjacjalizacja(kolejka k, int n, double tab[n])
{
    k[0]=k[1]=k[2]=tab;
    k[3]=tab+n;
}
void oproznianie(kolejka k,int n,double tab[n])
{
    k[1]=k[2];
    for (int i=0; i<n; i++)
        tab[i]=0;
}
void dopisywaniepoczatek(kolejka k, double x)
{
    if (pelna(k))
        return NAN;
    else
    {
        if (k[1]==k[0])
        {
            *(k[3]-1)=x;
            k[1]=k[3]-1;
        }
        else
        {
            *(k[1]-1)=x;
            k[1]--;
        }
    }
}
void dopisywaniekoniec(kolejka k, double x)
{
    if (pelna(k))
        return NAN;
    else
    {
        if (k[2]==k[3])
        {
            *k[0]=x;
            k[2]=k[0]+1;
        }
        else
        {
            *k[2]=x;
            k[2]++;
        }
    }
}
double pobieraniepoczatek(kolejka k)
{

    if (!pusta(k))
    {
        double x=*k[1];
        *k[1]=0;
        if (k[1]+1==k[3])
            k[1]=k[0];
        else
            k[1]++;
        return x;
    }
    return NAN;
}
double pobieraniekoniec(kolejka k)
{
    double x;
    if (!pusta(k))
    {
        x=*(k[2]-1);
        *(k[2]-1)=0;
        if (k[2]==k[0])
            k[2]=k[3]-1;
        else
            k[2]--;
        return x;
    }
    return NAN;
}
void wypisz(int n, double t[n])
{
    for (int i=0; i<n; i++)
        printf("%lf ", t[i]);
    printf ("\n");
}
