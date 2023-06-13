#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
typedef struct node
{
    bool czy_liczba;
    double liczba;
    char operacja;
    struct node *lewy, *prawy;
} Node;
Node *nowy_lisc(double x)
{
    Node *lisc;
    lisc=malloc(sizeof(Node));
    lisc->liczba=x;
    lisc->czy_liczba=true;
    return lisc;
}
Node *nowa_oper(char op, Node *lewy, Node *pr)
{
    Node *oper;
    oper=malloc(sizeof(Node));
    oper->czy_liczba=false;
    oper->operacja=op;
    oper->lewy=lewy;
    oper->prawy=pr;
    return oper;
}
Node *czytaj_onp(void)
{
    Node *stos[1000];
    int wierzcholek=0;
    double licz;
    char op;
    while (scanf(" %c", &op)==1)
    {
        if (isdigit(op))
        {
            ungetc(op,stdin);
            scanf("%lf", &licz);
            stos[wierzcholek]=nowy_lisc(licz);
            wierzcholek++;
        }
        else if (op=='=')
            break;
        else
        {
            Node *nowy=nowa_oper(op,stos[wierzcholek-2],stos[wierzcholek-1]);
            wierzcholek--;
            stos[wierzcholek-1]=nowy;
        }
    }
    return stos[0];
}
void wypisz(Node *wezel)
{
    if (wezel->czy_liczba==true)
        printf("%f ", wezel->liczba);
    else if ((wezel->prawy->operacja=='+' || wezel->prawy->operacja=='-') && wezel->operacja=='-')
    {
        wypisz(wezel->lewy);
        printf("%c ", wezel->operacja);
        printf("( ");
        wypisz(wezel->prawy);
        printf(") ");
    }
    else if ((wezel->prawy->operacja=='+' || wezel->prawy->operacja=='-') && (wezel->operacja=='*' || wezel->operacja=='/') && (wezel->lewy->operacja=='*' || wezel->lewy->operacja=='/'))
    {
        wypisz(wezel->lewy);
        printf("%c ", wezel->operacja);
        printf("( ");
        wypisz(wezel->prawy);
        printf(") ");
    }
    else if ((wezel->prawy->operacja=='+' || wezel->prawy->operacja=='-') && (wezel->operacja=='*' || wezel->operacja=='/') && (wezel->lewy->operacja=='+' || wezel->lewy->operacja=='-'))
    {
        printf("( ");
        wypisz(wezel->lewy);
        printf(") ");
        printf("%c ", wezel->operacja);
        printf("( ");
        wypisz(wezel->prawy);
        printf(") ");
    }
    else if ((wezel->prawy->operacja=='*' || wezel->prawy->operacja=='/') && (wezel->operacja=='*' || wezel->operacja=='/') && (wezel->lewy->operacja=='+' || wezel->lewy->operacja=='-'))
    {
        printf("( ");
        wypisz(wezel->lewy);
        printf(") ");
        printf("%c ", wezel->operacja);
        printf("( ");
        wypisz(wezel->prawy);
        printf(") ");
    }
    else if ((wezel->prawy->operacja=='+' || wezel->prawy->operacja=='-') && (wezel->operacja=='*' || wezel->operacja=='/') && (wezel->lewy->czy_liczba==true))
    {
        wypisz(wezel->lewy);
        printf("%c ", wezel->operacja);
        printf("( ");
        wypisz(wezel->prawy);
        printf(") ");
    }
    else if ((wezel->lewy->operacja=='+' || wezel->lewy->operacja=='-') && (wezel->operacja=='*' || wezel->operacja=='/') && (wezel->prawy->czy_liczba==true))
    {
        printf("( ");
        wypisz(wezel->lewy);
        printf(") ");
        printf("%c ", wezel->operacja);
        wypisz(wezel->prawy);

    }
    else
    {
        wypisz(wezel->lewy);
        printf(" %c ", wezel->operacja);
        wypisz(wezel->prawy);
    }
}
int main()
{
    Node *wyrazenie=czytaj_onp();
    wypisz(wyrazenie);
    return 0;
}
