typedef double *kolejka[4];
bool pelna(kolejka k);
bool pusta(kolejka k);
void inicjacjalizacja(kolejka k, int n, double tab[n]);
void oproznianie(kolejka k,int n,double tab[n]);
void dopisywaniepoczatek(kolejka k, double x);
void dopisywaniekoniec(kolejka k, double x);
double pobieraniepoczatek(kolejka k);
double pobieraniekoniec(kolejka k);
void wypisz(int n, double tab[n]);
