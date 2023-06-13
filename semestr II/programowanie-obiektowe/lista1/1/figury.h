#include <stdio.h>
#include <stdlib.h>
typedef struct figura{
int rodzaj;
float x1;
float y1;
float x2;
float y2;
float x3;
float y3;
float dlugosc;
} Figura;
Figura* nowy_trojkat(float x_1, float y_1,float x_2, float y_2,float x_3, float y_3);
Figura* nowy_kwadrat(float x, float y, float dlugosc_boku);
Figura* nowy_okrag(float wspolrzedna_x, float wspolrzedna_y, float promien);
float pole(Figura *f);
void przesun(Figura *f, float x, float y);
float sumapol(Figura *f, int size);
