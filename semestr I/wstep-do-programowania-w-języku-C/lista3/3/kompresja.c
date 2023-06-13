#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
void wczytywaniep1(bool tab[1024][1024], int bok)
{
    int c;
    for (int i=0; i<bok; i++)
        for (int j=0; j<bok; j++)
        {
            scanf("%d", &c);
            if (c==1)
                tab[i][j]=1;
            else
                tab[i][j]=0;
        }
}
void wczytywanierr(bool tab[1024][1024], bool tab2[1024*1024], int bok)
{
    int c,s=0,aktualna=0,l=0;
    while(s<bok*bok)
    {
        scanf("%d", &c);
        s+=c;
        for (int i=0; i<c; i++)
        {
            tab2[l]=aktualna;
            l++;
        }
        aktualna=(aktualna-1)*(-1);
    }
    for (int i=0; i<bok; i++)
    {
        for(int j=0; j<bok; j++)
            tab[i][j]=tab2[i*bok+j];
    }
}
void wczytywaniers(bool tab[1024][1024], bool tab2[1024*1024], int bok)
{
    int c,s=0,aktualna=0,l=0;
    while(s<bok*bok)
    {
        scanf("%d", &c);
        s+=c;
        for (int i=0; i<c; i++)
        {
            tab2[l]=aktualna;
            l++;
        }
        aktualna=(aktualna-1)*(-1);
    }
    for (int i=0; i<bok; i++)
    {
        if (i%2==0)
            for(int j=0; j<bok; j++)
                tab[i][j]=tab2[i*bok+j];
        else
            for (int j=bok-1; j>=0; j--)
                tab[i][bok-1-j]=tab2[i*bok+j];
    }
}
void wczytywanierd(bool tab[1024][1024], bool tab2[1024*1024], int bok)
{
    int c,s=0,aktualna=0,l=0;
    while(s<bok*bok)
    {
        scanf("%d", &c);
        s+=c;
        for (int i=0; i<c; i++)
        {
            tab2[l]=aktualna;
            l++;
        }
        aktualna=(aktualna-1)*(-1);
    }
    int stancja=1;
    int p=0,i=0,j=0;
    while(p<bok*bok)
    {
        tab[i][j]=tab2[p];
        if (stancja)
        {
            if (i-1>=0 && j+1<bok)
            {
                i--;
                j++;
            }
            else if (j+1<bok)
            {
                j++;
                stancja=0;
            }
            else
            {
                i++;
                stancja=0;
            }
        }
        else
        {
            if (i+1<bok && j-1>=0)
            {
                i++;
                j--;
            }
            else if(i+1<bok)
            {
                i++;
                stancja=1;
            }
            else
            {
                j++;
                stancja=1;
            }
        }
        p++;
    }
}

int wynikrr(bool tab[1024][1024], int bok)
{
    int aktualna=0,s=1;
    for (int i=0; i<bok; i++)
        for(int j=0; j<bok; j++)
            if (tab[i][j]!=aktualna)
            {
                aktualna=(aktualna-1)*(-1);
                s+=1;
            }
    return s;
}
int wynikrs(bool tab[1024][1024], int bok)
{
    int aktualna=0,s=1;
    for (int i=0; i<bok; i++)
    {
        if (i%2==0)
            for(int j=0; j<bok; j++)
            {
                if(tab[i][j]!=aktualna)
                {
                    s+=1;
                    aktualna=(aktualna-1)*(-1);
                }
            }
        else
            for (int j=bok-1; j>=0; j--)
                if(tab[i][j]!=aktualna)
                {
                    s+=1;
                    aktualna=(aktualna-1)*(-1);
                }

    }
    return s;
}
int wynikrd(bool tab[1024][1024], int bok)
{
    int aktualna=0,s=1;
    int stancja=1;
    int p=0,i=0,j=0;
    while(p<bok*bok)
    {
        if (tab[i][j]!=aktualna)
        {
            aktualna=(aktualna-1)*(-1);
            s+=1;
        }
        if (stancja)
        {
            if (i-1>=0 && j+1<bok)
            {
                i--;
                j++;
            }
            else if (j+1<bok)
            {
                j++;
                stancja=0;
            }
            else
            {
                i++;
                stancja=0;
            }
        }
        else
        {
            if (i+1<bok && j-1>=0)
            {
                i++;
                j--;
            }
            else if(i+1<bok)
            {
                i++;
                stancja=1;
            }
            else
            {
                j++;
                stancja=1;
            }
        }
        p++;
    }
    return s;
}
int main()
{
    bool tab[1024][1024];
    char a,b;
    int n,m ;
    a=getchar();
    b=getchar();
    scanf("%d", &n);
    bool tab2[n*n];
    if (a=='P' && b=='1')
    {
        scanf("%d", &m);
        wczytywaniep1(tab,n);
    }
    if (a=='R' && b=='R')
    {
        wczytywanierr(tab, tab2,n);
    }
    if (a=='R' && b=='S')
    {
        wczytywaniers(tab,tab2,n);
    }
    if (a=='R' && b=='D')
    {
        wczytywanierd(tab,tab2, n);
    }
    int x=wynikrr(tab,n);
    printf("%d ", x);
    int y=wynikrs(tab,n);
    printf("%d ", y);
    int z=wynikrd(tab,n);
    printf ("%d", z);
    return 0;
}
