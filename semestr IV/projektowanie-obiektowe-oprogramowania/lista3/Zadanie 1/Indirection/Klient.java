package zadanie1.indirection;

public class Klient {

    int fundusz;

    public void kup(Ksiazka ksiazka) {

        if (fundusz > 10){
            fundusz -=10;
            System.out.println("Ksiazka zostala kupiona");
        }
        else
            System.out.println("Brak pieniedzy, aby zakupic ksiazke");

    }
}
