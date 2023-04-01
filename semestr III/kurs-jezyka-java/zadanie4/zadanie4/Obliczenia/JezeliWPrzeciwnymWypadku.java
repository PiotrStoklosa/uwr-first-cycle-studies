package Obliczenia;

public class JezeliWPrzeciwnymWypadku extends Instrukcja{

    InstrukcjaBlokowa instrukcjaBlokowa1;
    InstrukcjaBlokowa instrukcjaBlokowa2;
    Wyrazenie warunek;

    public JezeliWPrzeciwnymWypadku(Wyrazenie warunek, InstrukcjaBlokowa instrukcjaBlokowa1, InstrukcjaBlokowa instrukcjaBlokowa2) throws Exception {

        if (warunek==null || instrukcjaBlokowa1==null || instrukcjaBlokowa2==null)
            throw new Exception("Oczekiwano warunku oraz dwoch instrukcji, dostano null!");

        this.instrukcjaBlokowa1 = instrukcjaBlokowa1;
        this.instrukcjaBlokowa2 = instrukcjaBlokowa2;
        this.warunek = warunek;

    }

    @Override
    public void wykonaj() throws Exception {

        if (warunek.oblicz()!=0)
            instrukcjaBlokowa1.wykonaj();
        else
            instrukcjaBlokowa2.wykonaj();
    }
}
