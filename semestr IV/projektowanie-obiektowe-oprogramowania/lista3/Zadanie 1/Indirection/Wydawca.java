package zadanie1.indirection;

public class Wydawca {

    private Ksiazka ksiazka;

    public void sprzedajKsiazke(Sklep sklep){

        sklep.sprzedaj(ksiazka);
    }


}
