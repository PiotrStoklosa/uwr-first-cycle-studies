struct element
{
    char *napis;
    struct element *next;
};
struct lista
{
    struct element *ostatni;
    struct element *pierwszy;
};
struct element *nowa_lista(void);
void stworz(struct lista *l);
struct element *dodajpoczatek(struct lista *l, char *tekst);
struct element *dodajkoniec(struct lista *l, char *tekst);
char *poczatek(struct lista *l);
char *usunpoczatek(struct lista *l);
bool pusta(struct lista *l);
int dlugosc(struct lista *l);
void wypisz(struct lista *l);
void sklej(struct lista *a, struct lista *b);
struct lista skopiuj(struct lista *l);
