#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void wczytywanie(bool tab[1000][1000], int a, int b)
{
    for (int i=0; i<b; i++)
        for (int j=0; j<a; j++)
        {
            char p=getchar();
            if (p=='\n')
                p=getchar();
            if (p==' ')
                tab[j][i]=0;
            else
                tab[j][i]=1;
        }
}
void wypisywanie(bool tab[1000][1000], int a, int b)
{
    for (int i=0; i<b; i++)
    {
        for (int j=0; j<a; j++)
        {
            if (tab[j][i]==false)
                printf(" ");
            else
                printf("X");
        }
        printf("\n");
    }
}
void obrot90(bool tab[1000][1000], int a, int b)
{
    for (int j=b-1; j>=0; j--)
    {
        for (int i=a-1; i>=0; i--)
        {
            if (tab[j][i]==false)
                printf(" ");
            else
                printf("X");
        }
        printf("\n");
    }
}
void obrot180(bool tab[1000][1000], int a, int b)
{
    for (int i=b-1; i>=0; i--)
    {
        for (int j=a-1; j>=0; j--)
        {
            if (tab[j][i]==false)
                printf(" ");
            else
                printf("X");
        }
        printf("\n");
    }
}
void obrot270(bool tab[1000][1000], int a, int b)
{
    for (int j=0; j<b; j++)
    {
        for (int i=0; i<a; i++)
        {
            if (tab[j][i]==false)
                printf(" ");
            else
                printf("X");
        }
        printf("\n");
    }
}
int main()
{
    int a,b,c;
    bool tab[1000][1000];
    printf("Przyklad\n");
    tab[0][0]=1;tab[1][0]=1;tab[2][0]=1;tab[0][1]=0;tab[1][1]=1;tab[2][1]=0;tab[0][2]=0;tab[1][2]=0;tab[2][2]=0;
    wypisywanie(tab,3,3);
    printf("\n");
    obrot90(tab,3,3);
    printf("\n");
    obrot180(tab,3,3);
    printf("\n");
    obrot270(tab,3,3);
    printf("\n");
    printf("Podaj szerokosc obrazka\n");
    scanf("%d", &a);
    printf("Podaj wysokosc obrazka\n");
    scanf("%d", &b);
    wczytywanie(tab,a,b);
    printf("wypisywanie obrazka: \nbez obrotu: 0\nobroconego o 90 stopni: 1\nobroconego o 180 stopni: 2\nobroconego o 270 stopni: 3\n");
    scanf("%d", &c);
    if (c==0)
        wypisywanie(tab,a,b);
    if (c==1)
        obrot90(tab,a,b);
    if (c==2)
        obrot180(tab,a,b);
    if (c==3)
        obrot270(tab,a,b);
    return 0;
}
