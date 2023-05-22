#include "stos.hpp"

    void Stos::wloz(string napis)
    {
        if (ile==pojemnosc)
            throw invalid_argument("Stos jest juz pelny!");

        tablica[ile]=napis;
        ile++;
    }
    string Stos::sciagnij()
    {
        if (ile==0)
            throw invalid_argument("Nie mozna zdjac elementu z pustego stosu!");

        string top=tablica[ile-1];
        tablica[ile-1]="";
        ile--;
        return top;
    }
    string Stos::sprawdz()
    {
        if (ile==0)
            throw invalid_argument("Stos jest pusty!");

        string top=tablica[ile-1];
        return top;
    }
    int Stos::rozmiar()
    {
        return ile;
    }
    Stos::Stos(int poj)
    {
        if (poj<0 || poj>100)
            throw invalid_argument("Pojemnosc stosu musi byc w zakresie 1-100!");

        tablica = new string[poj];
        pojemnosc=poj;
        ile=0;
    }
    Stos::Stos(const Stos &stos)
    {
        tablica = stos.tablica;
        pojemnosc = stos.pojemnosc;
        ile = stos.ile;
    }
    Stos::Stos(const Stos &&stos)
    {
        tablica = stos.tablica;
        pojemnosc = stos.pojemnosc;
        ile = stos.ile;
    }
    Stos & Stos::operator= (const Stos&)
    {
        return *this;
    }
    Stos & Stos::operator= (const Stos&&)
    {
        return *this;
    }
    Stos::~Stos()
    {
        delete[] tablica;
    }
    Stos::Stos()
    {
        pojemnosc=1;
        ile=0;
    }
    Stos Stos::odwroc()
    {
        Stos new_stos(pojemnosc);
        for (int i=pojemnosc-1; i>=0; i--)
            new_stos.wloz(tablica[i]);

        return new_stos;
    }
    Stos::Stos(const initializer_list<string> &lista)
    {

        if (lista.size()>100)
            throw invalid_argument("Pojemnosc stosu musi byc w zakresie 1-100!");

        pojemnosc=lista.size();
        ile=0;
        tablica = new string[pojemnosc];

        for(auto i = lista.begin(); i != lista.end(); i++ )
        {
            tablica[ile]=*i;
            ile++;
        }
    }
    int Stos::getPojemnosc()
    {
        return pojemnosc;
    }
    void Stos::Wypisz()
    {
        for (int i=ile-1; i>=0; i--)
            cout<<tablica[i]<<" ";

        cout<<'\n';
    }
