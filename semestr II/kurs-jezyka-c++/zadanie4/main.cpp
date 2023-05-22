//Piotr Stoklosa Zadanie4
#include "stos.hpp"

int main()
{
    Stos *stos = new Stos(50);
    bool wyjscie = false;
    string wybor;
    string wartosc;

    cout<<"Stworzono pusty stos o pojemnosci 50, operacje jakie mozesz wykonac:\n\n";
    cout<<"Wstawianie elementu: wstaw <element>\n";
    cout<<"Usuniecie elementu: usun\n";
    cout<<"Sprawdz ile elementow jest na stosie: rozmiar\n";
    cout<<"Wypisz pojemnosc: pojemnosc\n";
    cout<<"Wypisz stos: wypisz\n";
    cout<<"Wypisanie elementu na szczycie stosu: sprawdz\n";
    cout<<"Zakoncz dzialanie programu: wyjscie\n\n";

    while(!wyjscie)
    {
        cout<<"Wybierz odpowiednia opcje:\n";
        cin>>wybor;

        if (wybor=="wstaw")
        {
            cin>>wartosc;
            stos->wloz(wartosc);
        }

        else if (wybor=="usun")
            cout<<"Usuniety element: "<<stos->sciagnij()<<'\n';

        else if(wybor == "rozmiar")
            cout<<"Ilosc elementow na stosie: "<<stos->rozmiar()<<'\n';

        else if (wybor=="pojemnosc")
            cout<<stos->getPojemnosc();

        else if (wybor=="wypisz")
            stos->Wypisz();

        else if(wybor == "sprawdz")
            cout<<"Element na szczycie stosu: "<<stos->sprawdz()<<'\n';

        else if(wybor == "wyjscie")
            wyjscie=true;

        else
            cout<<"Brak takiej opcji!\n";

        cout<<'\n';
    }

    delete stos;

    return 0;
}

