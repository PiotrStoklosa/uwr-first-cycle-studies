package Obliczenia;

import java.util.Map;
import java.util.TreeMap;

public class DeklaracjaZmiennej extends Instrukcja{

    private Zmienna zmienna;


    public DeklaracjaZmiennej(Zmienna zmienna) throws Exception {
        if (zmienna==null)
            throw new Exception("Oczekiwano zmiennej, dostano null!");
        this.zmienna = zmienna;
    }

    @Override
    public void wykonaj() {
        Zmienna.add(zmienna);
    }
}
