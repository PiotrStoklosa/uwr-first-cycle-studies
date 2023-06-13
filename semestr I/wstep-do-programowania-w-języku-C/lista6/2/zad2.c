#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
void generator (int n, double tab[n])
{
    int p,z;
    double a;

    int x = time(NULL);
    srand(x);
    for (int i=0; i<n; i++)
    {
        tab[i]=rand();
        z=rand();
        p=10;
        while(z)
        {
            a=z%10;
            a/=p;
            tab[i]+=a;
            p*=10;
            z/=10;
        }
    }
}
void sortowanie(int n, double tab[n])
{
    for(int i=0; i<n; i++)
    {
        double mini=tab[i];
        int index=i;
        for(int j=i+1; j<n; j++)
        {
            if(tab[j]<mini)
            {
                mini=tab[j];
                index=j;
            }

        }
        double pom=tab[i];
        tab[i]=tab[index];
        tab[index]=pom;
    }
}
bool sprawdzenie(int n, double tab[n]/*, double tab2[n]*/)
{
    for(int i=0; i<n-1; i++)
        if(tab[i]>tab[i+1])
            return false;
    // Ta tablica jest permutacj¹ pocz¹tkowej tablicy, poniewa¿ jedyna operacja jaka wykonuje na niej jest zamiana dwoch elementow
    return true;
}
int porownaj(const void *p,const void *q)
{
    double *xp, *yp;
    xp=(double *)p;
    yp=(double *)q;
    return (*xp < *yp ? -1 : (*xp == *yp ? 0 : 1));
}
void test1()
{
    int czasprzed,x;
    int zestaw=100, rozmiar1=5000;
    int mini1=100000, maks1=0, srednia1=0;
    int qmini1=100000, qmaks1=0, qsrednia1=0;
    for (int i=0; i<zestaw; i++)
    {
        double tab[rozmiar1],d[rozmiar1];
        generator(rozmiar1,tab);
        for (int i=0; i<rozmiar1; i++)
            d[i]=tab[i];
        czasprzed=clock();
        sortowanie(rozmiar1,tab);
        x=clock()-czasprzed;
        if (x>maks1)
            maks1=x;
        if (x<mini1)
            mini1=x;
        srednia1+=x;
        czasprzed=clock();
        qsort(d,rozmiar1,sizeof(double), porownaj);
        x=clock()-czasprzed;
        if (x>qmaks1)
            qmaks1=x;
        if (x<qmini1)
            qmini1=x;
        qsrednia1+=x;
    }
    srednia1/=zestaw;
    qsrednia1/=zestaw;
    printf("Czasy dla 100 zestawow po 5000 liczb kazdy:\n\nDla sortowanie przez wybieranie:\n\n");
    printf("czas minimalny:  %d\n", mini1);
    printf("czas maksymalny: %d\n", maks1);
    printf("czas sredni:     %d\n\n", srednia1);
    printf("Dla sortowania szybkiego:\n\n");
    printf("czas minimalny:  %d\n", qmini1);
    printf("czas maksymalny: %d\n", qmaks1);
    printf("czas sredni:     %d\n\n", qsrednia1);
}
void test2()
{
    int czasprzed,x;
    int zestaw=100, rozmiar2=10000;
    int mini2=100000, maks2=0, srednia2=0;
    int qmini2=100000, qmaks2=0, qsrednia2=0;
    for (int i=0; i<zestaw; i++)
    {
        double tab[rozmiar2],d[rozmiar2];
        generator(rozmiar2,tab);
        for (int i=0; i<rozmiar2; i++)
            d[i]=tab[i];
        czasprzed=clock();
        sortowanie(rozmiar2,tab);
        x=clock()-czasprzed;
        if (x>maks2)
            maks2=x;
        if (x<mini2)
            mini2=x;
        srednia2+=x;
        czasprzed=clock();
        qsort(d,rozmiar2,sizeof(double), porownaj);
        x=clock()-czasprzed;
        if (x>qmaks2)
            qmaks2=x;
        if (x<qmini2)
            qmini2=x;
        qsrednia2+=x;
    }
    srednia2/=zestaw;
    qsrednia2/=zestaw;
    printf("Czasy dla 100 zestawow po 10000 liczb kazdy:\n\nDla sortowania przez wybieranie:\n\n");
    printf("czas minimalny:  %d\n", mini2);
    printf("czas maksymalny: %d\n", maks2);
    printf("czas sredni:     %d\n\n", srednia2);
    printf("Dla sortowania szybkiego:\n\n");
    printf("czas minimalny:  %d\n", qmini2);
    printf("czas maksymalny: %d\n", qmaks2);
    printf("czas sredni:     %d\n\n", qsrednia2);
}
void test3()
{
    int czasprzed,x;
    int zestaw=100, rozmiar3=50000;
    int mini3=100000, maks3=0, srednia3=0;
    int qmini3=100000, qmaks3=0, qsrednia3=0;
    for (int i=0; i<zestaw; i++)
    {
        double tab[rozmiar3],d[rozmiar3];
        generator(rozmiar3,tab);
        for (int i=0; i<rozmiar3; i++)
            d[i]=tab[i];
        czasprzed=clock();
        sortowanie(rozmiar3,tab);
        x=clock()-czasprzed;
        if (x>maks3)
            maks3=x;
        if (x<mini3)
            mini3=x;
        srednia3+=x;
        czasprzed=clock();
        qsort(d,rozmiar3,sizeof(double), porownaj);
        x=clock()-czasprzed;
        if (x>qmaks3)
            qmaks3=x;
        if (x<qmini3)
            qmini3=x;
        qsrednia3+=x;
    }
    srednia3/=zestaw;
    qsrednia3/=zestaw;
    printf("Czasy dla 100 zestawow po 50000 liczb ka¿dy:\n\nDla sortowania przez wybieranie:\n\n");
    printf("czas minimalny:  %d\n", mini3);
    printf("czas maksymalny: %d\n", maks3);
    printf("czas sredni:     %d\n\n", srednia3);
    printf("Dla sortowania szybkiego:\n\n");
    printf("czas minimalny:  %d\n", qmini3);
    printf("czas maksymalny: %d\n", qmaks3);
    printf("czas sredni:     %d\n\n", qsrednia3);
}
