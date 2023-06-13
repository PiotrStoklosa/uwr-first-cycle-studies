#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
char tab[105][105];
bool odw[105][105][(1<<12)+5];
int war[105][105];
void dfs(int x, int y, int maska)
{
    odw[x][y][maska]=true;
    if (odw[x+1][y][maska|war[x+1][y]]==false && tab[x+1][y]!='#' && (maska&war[x+1][y])==0)
        dfs(x+1,y,maska+war[x+1][y]);
    if (odw[x][y+1][maska|war[x][y+1]]==false && tab[x][y+1]!='#' && (maska&war[x][y+1])==0)
        dfs(x,y+1,maska+war[x][y+1]);
    if (odw[x-1][y][maska|war[x-1][y]]==false && tab[x-1][y]!='#' && (maska&war[x-1][y])==0)
        dfs(x-1,y,maska+war[x-1][y]);
    if (odw[x][y-1][maska|war[x][y-1]]==false && tab[x][y-1]!='#' && (maska&war[x][y-1])==0)
        dfs(x,y-1,maska+war[x][y-1]);
}
int main()
{
    int a,b,c=1,maks=0;
    scanf("%d", &b);
    scanf("%d", &a);
    for (int i=1; i<=a; i++)
        for (int j=1; j<=b; j++)
            {
                scanf(" %c", &tab[i][j]);
                if (tab[i][j]=='S')
                {
                    maks+=c;
                    war[i][j]=c;
                    c*=2;
                }
                else
                    war[i][j]=0;
            }

    for (int i=0; i<=a+1; i++)
        for (int j=0; j<=b+1; j++)
            if (i==0 || j==0 || i==a+1 || j==b+1)
                {
                    tab[i][j]='#';
                    war[i][j]=0;
                }
    for (int i=1; i<=a; i++)
        for (int j=1; j<=b; j++)
            if (tab[i][j]=='L')
                dfs(i,j,0);
    for (int i=1; i<=a; i++)
    {
        for (int j=1; j<=b; j++)
            {
                if (odw[i][j][maks]==true)
                    printf("X");
                else if (tab[i][j]=='S' || tab[i][j]=='L')
                    printf(".");
                else
                    printf("%c", tab[i][j]);
            }
        printf("\n");
    }
    return 0;
}
