#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool tab[1024][1024];
int tab2[1024][1024];
int main()
{
    char a,b;
    scanf("%c %c", &a, &b);
    int x,y,l,c,aktualna,maks=0;
    scanf("%d %d", &x, &y);
    for (int i=0; i<y; i++)
        for(int j=0; j<x; j++)
        {
            scanf("%d", &c);
            if (c==1)
                tab[i][j]=1;
            else
                tab[i][j]=0;
            tab2[i][j]=1;
        }
    for (int i=0; i<x; i++)
    {
        aktualna=tab[0][i];
        l=1;
        for(int j=i+1; j<x; j++)
        {
            if (tab[0][j]!=aktualna)
            {
                l++;
                aktualna=(aktualna-1)*(-1);
            }
            else
                break;
        }
        aktualna=tab[0][i];
        tab2[0][i]=l;
        l=1;
        for(int j=i-1; j>=0; j--)
        {
            if (tab[0][j]!=aktualna)
            {
                l++;
                aktualna=(aktualna-1)*(-1);
            }
            else
                break;
        }
        if (tab2[0][i]<l)
            tab2[0][i]=l;
        if (tab2[0][i]>maks)
            maks=tab2[0][i];
    }
    for (int i=1; i<y; i++)
        for (int j=0; j<x; j++)
        {
            aktualna=tab[i][j];
            l=1;
            if (tab[i-1][j]!=tab[i][j] && tab2[i][j]<tab2[i-1][j]+1)
                tab2[i][j]=tab2[i-1][j]+1;
            for(int k=j+1; k<x; k++)
            {
                if (tab[i][k]!=aktualna)
                {
                    l++;
                    aktualna=(aktualna-1)*(-1);
                    if (aktualna!=tab[i-1][k])
                        if(tab2[i][j]<l+tab2[i-1][k])
                            tab2[i][j]=l+tab2[i-1][k];
                    if (l>tab2[i][j])
                        tab2[i][j]=l;
                }
                else
                    break;
            }
            aktualna=tab[i][j];
            l=1;
            for(int k=j-1; k>=0; k--)
            {
                if (tab[i][k]!=aktualna)
                {
                    l++;
                    aktualna=(aktualna-1)*(-1);
                    if (aktualna!=tab[i-1][k])
                        if(tab2[i][j]<l+tab2[i-1][k])
                            tab2[i][j]=l+tab2[i-1][k];
                    if (l>tab2[i][j])
                        tab2[i][j]=l;
                }
                else
                    break;
            }
            if (tab2[i][j]>maks)
                maks=tab2[i][j];
        }
    printf("%d", maks);
    return 0;
}
