#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool poprawneustawienie(int n, int p[n])
{
    int a,b;
    for(int i=0; i<n; i++)
    {
        a=p[i]-i,b=p[i]+i;
        for(int j=i+1; j<n; j++)
            if(a==p[j]-j || b==p[j]+j)
                return false;
    }
    return true;
}
bool next_perm(int n, int p[n])
{
    if (n==1)
        return false;
    if (!next_perm(n-1,p+1))
    {
        if (p[0]>p[1])
            return false;
        else
        {
            for (int i=n-1; i>0; i--)
                if (p[i]>p[0])
                {
                    int c=p[0];
                    p[0]=p[i];
                    p[i]=c;
                    break;
                }
            for (int i=1; i<n/2+n%2; i++)
            {
                int v=p[i];
                p[i]=p[n-i];
                p[n-i]=v;
            }
            return true;
        }
    }
    else
        return true;
}
int main()
{
    int n,k;
    scanf("%d", &n);
    scanf("%d", &k);
    int p[n];
    for (int i=1; i<=n; i++)
        p[i-1]=i;
    do
    {
        if (poprawneustawienie(n,p))
        {
            if (!k)
                return 0;
            k--;
            {
                for(int i=0; i<n; i++)
                    printf("%d ", p[i]);
                printf("\n");
            }
        }
    }
    while(next_perm(n,p));
    return 0;
}
