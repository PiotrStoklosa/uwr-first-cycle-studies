#include <iostream>
#include <string>
#include <initializer_list>

using namespace std;

class Stos{

    private:
        string *tablica;
        int pojemnosc;
        int ile;
    public:
        Stos(int poj);
        Stos(const Stos &stos);
        Stos(const Stos &&stos);
        ~Stos();
        Stos();
        Stos odwroc();
        Stos(const initializer_list<string>&);

        Stos& operator= (const Stos&);
        Stos& operator= (const Stos&&);

        int getPojemnosc();
        void Wypisz();
        void wloz(string napis);
        string sciagnij();
        string sprawdz();
        int rozmiar();
};
