#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node *pnode;

typedef struct node{
int val;
pnode left;
pnode right;
} snode;

pnode utworz(int wart)
{
pnode pom;
pom = (pnode) malloc(sizeof(snode));
pom->left = NULL;
pom->right = NULL;
pom->val = wart;
return pom;
}
pnode insert( pnode root, int nkey)
{
if(root==NULL)
    return utworz(nkey);
if (nkey< root->val)
    root->left =insert(root->left, nkey);
else if (nkey> root->val)
    root->right =insert(root->right, nkey);
return root;
}
int ilosc_elementow(pnode t) // 2 slabe
{
    if (t->left!=NULL)
    {
        if (t->right!=NULL)
            return 1 + ilosc_elementow(t->left) + ilosc_elementow(t->right);
        else
            return 1 + ilosc_elementow(t->left);
    }
    else if (t->right!=NULL)
        return 1+ ilosc_elementow(t->right);
    else
        return 1;
}
int il(pnode t)//2
{
    if (t!=NULL)
        return 1+il(t->left) + il(t->right);
    return 0;
}
int wysokosc(pnode t) //3
{
    if (t->left==NULL)
    {
        if (t->right==NULL)
            return 1;
        return 1 + wysokosc(t->right);
    }
    else if (t->right==NULL)
        return 1 + wysokosc(t->left);
    int a= wysokosc(t->left);
    int b= wysokosc(t->right);
    if (a>b)
        return a +1;
    return b + 1;
}
void write_possitive( pnode root )//4
{
    if (root!=NULL)
    {
        if (root->val>0)
        {
            write_possitive( root->left);
            printf("%d\n", root->val);
        }
        write_possitive( root->right);
    }
}
int pom[1000000];
void czy_BST( pnode root)//5a
{
    if (root!=NULL)
    {
        czy_BST( root->left);
        int i=0;
        while(pom[i])
            i++;
        pom[i]=root->val;
        czy_BST( root->right);
    }
}
bool czy(pnode root)//5b
{
    int wysok=ilosc_elementow(root);
    czy_BST(root);
    for (int i=0; i<wysok-1; i++)
        {
           if (pom[i]>pom[i+1])
                return false;
        }
    return true;
}
pnode polacz(pnode root1, pnode root2)//6
{
    if (root1==NULL && root2==NULL)
        return NULL;
    if (root1==NULL)
        return root2;
    pnode poczatek=root2;
    while(root2->left!=NULL)
        root2=root2->left;
    root2->left=root1;
    return poczatek;
}
int main()
{
    pnode drzewo=utworz(8);
    //drzewo->left=utworz(7);
    drzewo= insert(drzewo,2);
    drzewo= insert(drzewo,6);
    drzewo= insert(drzewo,1);
    drzewo= insert(drzewo,3);
    drzewo= insert(drzewo,5);
    drzewo= insert(drzewo,7);
   /* pnode drzewo2=utworz(15);
    drzewo2= insert(drzewo2,17);
    drzewo2= insert(drzewo2,28);
    drzewo2= insert(drzewo2,13);
    drzewo2= insert(drzewo2,19);
    drzewo2= insert(drzewo2,589);
    drzewo2= insert(drzewo2,8888);*/
    //drzewo=polacz(drzewo, drzewo2);
    //printf("%d\n", ilosc_elementow(drzewo));
    printf("%d\n", il(drzewo));
    bool x= czy(drzewo);
    if (x==true)
        printf("True");
    else
        printf("False");
    return 0;
}
