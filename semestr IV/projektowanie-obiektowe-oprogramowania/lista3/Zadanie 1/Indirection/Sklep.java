package zadanie1.indirection;

public class Sklep {

    Wydawca wydawca;
    Klient klient;


    public void sprzedaj(Ksiazka ksiazka) {

        klient.kup(ksiazka);

    }
}
