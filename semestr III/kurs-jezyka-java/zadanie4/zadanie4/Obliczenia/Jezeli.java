package Obliczenia;

public class Jezeli extends Instrukcja{

    InstrukcjaBlokowa instrukcjaBlokowa;
    Wyrazenie warunek;

    public Jezeli(Wyrazenie warunek, InstrukcjaBlokowa instrukcjaBlokowa){

        this.instrukcjaBlokowa = instrukcjaBlokowa;
        this.warunek = warunek;

    }

    @Override
    public void wykonaj() throws Exception {

        if(warunek.oblicz()!=0)
            instrukcjaBlokowa.wykonaj();

    }
}
