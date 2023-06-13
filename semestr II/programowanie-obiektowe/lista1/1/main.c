#include <stdio.h>
#include <stdlib.h>
#include "figury.h"
int main()
{
    Figura tab[3];
    Figura *f=nowy_kwadrat(1,2,3);
    printf("Kwadrat: Wspolrzedne lewego dolnego punktu: %f,%f\nPole: %f\n", f->x1, f->y1, pole(f));
    przesun(f,4,6);
    printf("Kwadrat po przesunieciu o wektor (4,6): Wspolrzedne lewego dolnego punktu: %f,%f\n\n", f->x1, f->y1);
    tab[0]=*f;
    f=nowy_okrag(1,3.5,5);
    printf("okrag: Wspolrzedne srodka: %f,%f\nPole: %f\n", f->x1, f->y1, pole(f));
    przesun(f,2,-3);
    printf("okrag po przesunieciu o wektor (2,-3): Wspolrzedne srodka: %f,%f\n\n", f->x1, f->y1);
    tab[1]=*f;
    f=nowy_trojkat(1,1,2,2,3,-6);
    printf("Trojkat: Wspolrzedne: %f,%f  %f,%f  %f,%f  \nPole: %f\n", f->x1, f->y1,f->x2, f->y2,f->x3, f->y3, pole(f));
    przesun(f,-3,0);
    printf("Trojkat po przesunieciu o wektor (-3,0): Wspolrzedne: %f,%f  %f,%f  %f,%f\n\n", f->x1, f->y1,f->x2, f->y2,f->x3, f->y3);
    tab[2]=*f;
    printf("Suma pol wszystkich trzech figur: %f\n\n", sumapol(&tab[0],3));
    printf("Przyklady blednie zainicjowanych figur:\n\n");
    printf("Kwadrat o boku -8.8: ");
    f=nowy_kwadrat(1,1,-8.8);
    printf("Okrag o promieniu 0: ");
    f=nowy_okrag(3,6,0);
    printf("Trojakt ktorego wszystkie wspolrzedne leza na jednej prostej: ");
    f=nowy_trojkat(1,1,2,2,3,3);

    return 0;
}
