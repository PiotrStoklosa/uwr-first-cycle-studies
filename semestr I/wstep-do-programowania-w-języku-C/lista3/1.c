#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int scan(int n, char tab[n])
{
    int i=1,c;
    c=getchar();
    while(isspace(c))
        c=getchar();
    if (c=='-')
        tab[0]='-';
    else
        tab[0]='+';
    if (c=='+' || c=='-')
        c=getchar();
    while(isdigit(c))
    {
        tab[i]=c;
        i++;
        if (i>n)
            return 1;
        c=getchar();
    }
    tab[i]='\0';
    i--;
    return i;
}
int convert(const char tab[10000], int tab3[10000], int b)
{
    if (tab[0]=='-')
        tab3[0]=0;
    else
        tab3[0]=1;
    tab3[1]=b;
    int p=2;
    for (int i=b; i>0; i--)
    {
        tab3[p]=(tab[i]-'0');
        p++;
    }
    return 0;
}
void wypisz(const int tab3[10000], const int tab4[10000])
{
    for (int i=0; i<tab3[1]+2; i++)
        printf("%d", tab3[i]);
    printf("\n");
    for (int i=0; i<tab4[1]+2; i++)
        printf("%d", tab4[i]);

}
int main()
{
    int x,y;
    char tab[10000], tab2[10000];
    int tab3[10000], tab4[10000];
    int wynikdod[10000]= {0},wynikode[10000]= {0}, wynikmno[10000]= {0};

    x=scan (10000, tab);
    y=scan (10000, tab2);
    convert(tab, tab3, x);
    convert(tab2, tab4, y);
    wypisz(tab3, tab4);
    return 0;
}
