#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
    int n;
    scanf("%d", &n);
    int p[n];
    for (int i=1; i<=n; i++)
        p[i-1]=i;
    do
    {
        for (int i=0; i<n; i++)
            printf("%d", p[i]);
        printf("\n");
    }
    while(next_perm(n,p));
    return 0;
}
