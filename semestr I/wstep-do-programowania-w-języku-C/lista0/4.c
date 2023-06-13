#include <stdio.h>
#include <stdlib.h>
long long int tab[1000000];
long long int wynik=0;
long long int f(long long int x)
    {
        long long int b=0;
        while(x>0)
        {
            int c=x%10;
            b+=(c*c);
            x/=10;
        }
        return b;
    }
int main()
{
    long long int a;
    scanf("%lld", &a);
    for(int i=0; i<10; ++i)
    {
        for (int j=0; j<1000000; ++j)
        {
            tab[j]=0;
        }
        long long int e=a+i;
        while(1)
        {
            e=f(e);
            if (e==1)
            {
                if (wynik==0)
                wynik=a+i;
                break;
            }
            else
            {
                if (tab[e]==1)
                    break;
                else
                    tab[e]=1;
            }
        }
    }
    if (wynik==0)
        printf("BRAK");
    else
        printf("%lld", wynik);
    return 0;
}
