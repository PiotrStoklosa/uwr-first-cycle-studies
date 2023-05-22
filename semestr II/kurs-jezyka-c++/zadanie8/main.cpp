// Piotr Stoklosa
#include "Szablon.hpp"

using namespace std;

int main()
{
    int wybor =  1;
    List<int> *lista = new List<int>();

    cout<<"Stworzono liste jednokierunkowa typu int. Dostepne operacje ktore zostana wykonane: \n\n";
    cout<<"1: Wstawienie elementu i na j-ta pozycje\n";
    cout<<"2: Usuwanie elementu i\n";
    cout<<"3: Zliczanie wszystkich elementów\n";
    cout<<"4: Wyszukanie i wypisanie pozycji elementu i\n";
    cout<<"5: Wypisanie listy\n";
    cout<<"0: Zakoncz dzialanie programu i usun liste\n";

    while(wybor)
    {
        cout<<"Prosze wybrac operacje: \n";
        int i,j;
        cin>>wybor;

        if (wybor<0 || wybor>5)
            cout<<"Nie ma takiej operacji!\n";

        if (wybor==1)
        {
            cout<<"Prosze podac i, j\n";
            cin>>i>>j;
            lista->wstaw(i,j);
            cout<<"Wstawiono!\n\n";
        }

        if (wybor==2)
        {
            cout<<"Prosze podac i\n";
            cin>>i;
            lista->usun(i);
            cout<<"Usunieto lub umieszczono odpowiedni komunikat o niepowodzeniu!\n\n";
        }

        if (wybor==3)
        {
            cout<<lista->zlicz()<<'\n';
            cout<<"Wypisano!\n\n";
        }

        if (wybor==4)
        {
             cout<<"Prosze podac i\n";
             cin>>i;
             cout<<"Pozycja elementu i: "<<lista->wyszukaj(i)<<'\n';
             cout<<"Wyszukano!\n\n";
        }

        if (wybor==5)
        {
            cout<<*lista<<'\n';
            cout<<"Wypisano!\n\n";
        }

    }

    delete lista;

    return 0;
}
