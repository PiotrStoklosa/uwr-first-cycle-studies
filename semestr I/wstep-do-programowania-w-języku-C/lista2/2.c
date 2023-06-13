#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    int m,n,i,p=0;
    char c;
    char tab[10000];
    char tab2[10000];
    scanf("%d %d", &m, &n);
    int k=m;
    for (int i=0; i<m-1; i++)
        printf(" ");
    while(c=getchar()!=EOF)
    {
        tab[i]=c;
        i++;
    }
    int j=0;
    while(j<=i)
    {
        if (k==m && p!=0)
        {
            printf("%s", tab2);
            for (int y=0; y<p; y++)
                tab2[y]='.';
            k+=p+1;
            p=0;
            printf (" ");
        }
        while (1)
        {
            if (isspace(tab[j])!=0)
                j++;
            else
                break;
        }
        while(1)
        {
            p=0;
            if (isspace(tab[j]==0))
                {
                    tab2[p]=tab[j];
                    p++;
                    j++;
                }
        }
        if (k+p<=n)
        {
            printf("%s", tab2);
            for (int y=0; y<p; y++)
                tab2[y]='.';
            k+=p+1;
            p=0;
            printf (" ");
        }
        else
        {
        printf("\n");
        for (int i=0; i<m-1; i++)
            printf(" ");
        k=m;
        }
    }
    return 0;

}
