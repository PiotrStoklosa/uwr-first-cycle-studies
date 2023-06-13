#include <stdio.h>
#include <stdlib.h>
#include "figury.h"
Figura* nowy_trojkat(float x_1, float y_1,float x_2, float y_2,float x_3, float y_3)
{
    if (((x_2-x_1)*(y_3-y_1)-(y_2-y_1)*(x_3-x_1))==0)
    {
        printf("Punkty nie moga lezec na jednej prostej!\n");
        return NULL;
    }
    Figura *f;
    f=malloc(sizeof(Figura));
    f->rodzaj=0;
    f->x1=x_1;
    f->y1=y_1;
    f->x2=x_2;
    f->y2=y_2;
    f->x3=x_3;
    f->y3=y_3;
    return f;
}
Figura* nowy_kwadrat(float x, float y, float dlugosc_boku)
{
    if (dlugosc_boku<=0)
    {
        printf("Dlugosc boku kwadratu musi byc dodatnia!\n");
    }
    Figura *f;
    f=malloc(sizeof(Figura));
    f->rodzaj=1;
    f->x1=x;
    f->y1=y;
    f->dlugosc=dlugosc_boku;
    return f;
}

Figura* nowy_okrag(float wspolrzedna_x, float wspolrzedna_y, float promien)
{
    if (promien<=0)
    {
        printf("Dlugosc promienia musi byc dodatnia!\n");
        return 0;
    }
    Figura *f;
    f=malloc(sizeof(Figura));
    f->rodzaj=2;
    f->x1=wspolrzedna_x;
    f->y1=wspolrzedna_y;
    f->dlugosc=promien;
    return f;
}
float pole(Figura *f)
{
    if (f->rodzaj==0)
        return 0.5*abs((f->x2-f->x1)*(f->y3-f->y1)-(f->y2-f->y1)*(f->x3-f->x1));
    if (f->rodzaj==1)
        return f->dlugosc*f->dlugosc;
    return 3.14159265*f->dlugosc*f->dlugosc;
}
void przesun(Figura *f, float x, float y)
{
    if (f->rodzaj==0)
    {
        f->x1+=x;
        f->x2+=x;
        f->x3+=x;
        f->y1+=y;
        f->y2+=y;
        f->y3+=y;
    }
    else
    {
        f->x1+=x;
        f->y1+=y;
    }
}
float sumapol(Figura *f, int size)
{
    float sum=0;
    for (int i=0; i<size; i++)
    {
        sum+=pole(f);
        f++;
    }
    return sum;
}
