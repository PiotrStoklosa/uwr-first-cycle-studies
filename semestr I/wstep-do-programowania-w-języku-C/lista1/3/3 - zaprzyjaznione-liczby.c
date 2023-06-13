#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
long long int f(long long int x)
{
    long long int p=1;
    long long int last=0;
    for (long long int i=2; i*i<=x; i++)
    {
        if (x%i==0)
        {
            last=i;
            p+=i+x/i;
        }
    }
    if(last*last==x)
        p-=last;
    return p;
}
int main()
{
    long long int test=0;
    long long int s;
    scanf("%lld", &s);
    long long int n=s;
    if (n==INT_MAX)
    {
        printf("BRAK");
        printf("\n");
        return 0;
    }
    n=n+1;
    if (n<2)
        n=2;
    while(n<INT_MAX)
    {
        long long int m=f(n);
        if (m<=INT_MAX && m>n)
        {
            long long int l=f(m);
            if (l==n)
            {
                printf("%lld", n);
                printf(" ");
                printf("%lld", m);
                n=INT_MAX-1;
                test=1;
            }
        }
        n=n+1;
    }
    if (test==0)
        printf("BRAK");
    printf("\n");
    return 0;
}
