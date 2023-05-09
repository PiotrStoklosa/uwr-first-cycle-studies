#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool odw[4];
bool krawedz[4][4];
typedef struct node{
    int wierzcholek;
    struct node *next;
} Node;
Node *tab[4];
Node *table[4];
void z_mac_na_lis(bool B[4][4])//1a
{
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<4; j++)
        {
            if (B[i][j]==true)
            {
                Node *nowy;
                nowy=malloc(sizeof(Node));
                nowy->next=NULL;
                nowy->wierzcholek=j;
                Node *pom=table[i];
                if (pom==NULL)
                {
                    table[i]=nowy;
                    continue;
                }
                while(pom->next!=NULL)
                    pom=pom->next;
                pom->next=nowy;
            }
        }
    }
}
bool B[4][4];
void z_lis_na_tab(Node *tab[4])//1b
{
    for (int i=0; i<4; i++)
    {
        Node *pom=tab[i];
        while(pom!=NULL)
        {
             B[i][pom->wierzcholek]=true;
             pom=pom->next;
        }
    }
}
void nowa_lista()
{
    int a,b,c;
    for (int i=0; i<4; i++)
        tab[i]=NULL;
    scanf("%d", &a);
    for (int i=0; i<a; i++)
    {
        scanf("%d %d", &b , &c);
        Node *nowy,*nowy2;

        nowy=malloc(sizeof(Node));
        nowy->next=NULL;
        nowy->wierzcholek=c;

        nowy2=malloc(sizeof(Node));
        nowy2->next=NULL;
        nowy2->wierzcholek=b;

        Node *pom=tab[b];
        Node *pom2=tab[c];

        if (pom==NULL)
        {
            tab[b]=nowy;
        }
        else
        {
            while(pom->next!=NULL)
                pom=pom->next;
            pom->next=nowy;
        }

        if (pom2==NULL)
        {
            tab[c]=nowy2;
            continue;
        }
        while(pom2->next!=NULL)
            pom2=pom2->next;
        pom2->next=nowy2;
    }
}
void dfs(int v)//2a
{
    odw[v]=true;
    Node *pom=tab[v];
    while(pom!=NULL)
    {
        if (!odw[pom->wierzcholek])
            dfs(pom->wierzcholek);
        pom=pom->next;
    }
}
void dfs_BEZ(int v, int i, int j)//2a
{
    odw[v]=true;
    Node *pom=tab[v];
    while(pom!=NULL && (v!=i || pom->wierzcholek!=j) && (v!=j || pom->wierzcholek!=i))
    {
        if (!odw[pom->wierzcholek])
            dfs(pom->wierzcholek);
        pom=pom->next;
    }
}
bool czy_spojny()//2b
{
    for (int i=0; i<4; i++)
        odw[i]=false;
    dfs(0);
    for (int i=0; i<4; i++)
        {
            if (odw[i]==false)
                return false;
        }
    return true;
}
bool czy_spojny2(int a, int b)//2b
{
    for (int i=0; i<4; i++)
        odw[i]=false;
    dfs_BEZ(0,a,b);
    for (int i=0; i<4; i++)
        {
            if (odw[i]==false)
                return false;
        }
    return true;
}
void usun(int x, int y)//2c
{

    if (tab[x]->wierzcholek==y)
        tab[x]=tab[x]->next;
    else
        {
            Node *poczatek=tab[x];
            while(tab[x]->next->wierzcholek!=y)
                tab[x]=tab[x]->next;
            if (tab[x]->next->next==NULL)
                tab[x]->next=NULL;
            else
                tab[x]->next=tab[x]->next->next;
            tab[x]=poczatek;
        }


    if (tab[y]->wierzcholek==x)
        tab[y]=tab[y]->next;
    else
        {
            Node *poczatek2=tab[y];
            while(tab[y]->next->wierzcholek!=x)
                tab[y]=tab[y]->next;
            if (tab[y]->next->next==NULL)
                tab[y]->next=NULL;
            else
                tab[y]->next=tab[y]->next->next;
            tab[y]=poczatek2;
        }

}
void wypisz()
{
    for (int i=0; i<4; i++)
    {
        Node *pom=tab[i];
        printf("%d: ", i);
        while(pom!=NULL)
            {
            printf(" %d ", pom->wierzcholek);
            pom=pom->next;
            }
            printf("\n");
    }
}
void wstaw(int a, int b)
{
   Node *nowy,*nowy2;

    nowy=malloc(sizeof(Node));
    nowy->next=NULL;
    nowy->wierzcholek=a;

    nowy2=malloc(sizeof(Node));
    nowy2->next=NULL;
    nowy2->wierzcholek=b;

    Node *pom=tab[a];
    Node *pom2=tab[b];

    if (pom==NULL)
    {
        tab[a]=nowy;
    }
    else
    {
        while(pom->next!=NULL)
            pom=pom->next;
        pom->next=nowy;
    }

    if (pom2==NULL)
    {
        tab[b]=nowy2;
        return;
    }
    while(pom2->next!=NULL)
        pom2=pom2->next;
    pom2->next=nowy2;
}
bool czy_most(Node *lista[4], int x, int y)//2d
{
    //usun(x,y);
    bool czy= czy_spojny2(x,y);
    //wstaw(x,y);
    if (czy)
        return 0;
    return 1;
}
Node *pom;
bool czy_istnieje_most()
{
    for (int i=0; i<4; i++)
    {
        pom=tab[i];
        while(pom!=NULL)
        {   if (krawedz[i][pom->wierzcholek]==false && krawedz[pom->wierzcholek][i]==false)
                if (czy_most(tab,i,pom->wierzcholek))
                    return true;
            pom=pom->next;
            krawedz[i][pom->wierzcholek]=true;
        }
    }
    return false;
}
int main()
{
    nowa_lista();
    if (czy_istnieje_most())
        printf("TAK");
    else
        printf("NIE");
    return 0;
}
