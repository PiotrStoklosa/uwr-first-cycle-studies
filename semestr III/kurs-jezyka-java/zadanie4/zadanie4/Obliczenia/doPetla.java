package Obliczenia;

public class doPetla extends Instrukcja{
    Wyrazenie warunek;
    InstrukcjaBlokowa petla;

    public doPetla(Wyrazenie warunek, InstrukcjaBlokowa petla) throws Exception {
        if (warunek==null || petla==null)
            throw new Exception("Oczekiwano warunku oraz petli, dostano null!");

        this.warunek = warunek;
        this.petla = petla;

    }

    @Override
    public void wykonaj() throws Exception {

        do {
            petla.wykonaj();

        }  while((warunek.oblicz()!=0));

    }
}
