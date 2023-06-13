#include <stdio.h>
#include <stdlib.h>
unsigned long long int tab[1000];
unsigned long long int war(unsigned long long int a, unsigned long long int baza)
{
    for (unsigned long long int i=0; i<1000; i++)
        tab[i]=0;
    unsigned long long int l=1;
    while(a>0)
    {
        tab[l]=a%baza;
        a/=baza;
        l+=1;
    }
    tab[0]=l-1;
    unsigned long long int s=0;
    unsigned long long int r;
    for (unsigned long long int i=1; i<=tab[0]; i++)
    {
        r=tab[i];
        for (unsigned long long int j=1; j<tab[0]; j++)
            r*=tab[i];
        s+=r;
    }
    return s;
}
int main()
{
    unsigned long long int n,b,c;
    scanf("%llu", &n);;
    for (unsigned long long int x=3; x<=10; x++)
    {
        printf("%llu ", x);
        for (unsigned long long int j=n; j>1; j++)
        {
            c=war(j,x);
            if (c==j)
            {
                printf("%llu ", c);
                for (unsigned long long int z=tab[0]; z>=1; z--)
                    printf("%llu", tab[z]);
                printf("\n");
                break;
            }
        }
    }
    return 0;
}
