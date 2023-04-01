package Obliczenia;

public class Petla extends Instrukcja{

    Wyrazenie warunek;
    InstrukcjaBlokowa petla;

    public Petla(Wyrazenie warunek, InstrukcjaBlokowa petla) throws Exception {

        if (warunek==null || petla==null)
            throw new Exception("Oczekiwano warunku oraz petli, dostano null!");

        this.warunek = warunek;
        this.petla = petla;

    }

    @Override
    public void wykonaj() throws Exception {

        while(warunek.oblicz()!=0)
            petla.wykonaj();

    }
}
