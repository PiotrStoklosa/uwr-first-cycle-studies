package Obliczenia;

import java.util.Map;
import java.util.TreeMap;

public class InstrukcjaBlokowa extends Instrukcja{

    Instrukcja[] array;

    public InstrukcjaBlokowa(Instrukcja... instrukcja){
        array = instrukcja;
    }

    @Override
    public void wykonaj() throws Exception {

        Map<String, Integer> Variable1 = new TreeMap<>();
        Map<String, Integer> Variable2 = new TreeMap<>();

        Variable1.putAll(Zmienna.getVariable());


        for (int i=0; i<array.length; i++)
            array[i].wykonaj();

        for (Map.Entry<String, Integer> entry : Zmienna.getVariable().entrySet())
            if (!Variable1.containsKey(entry.getKey()))
                Variable2.put(entry.getKey(),entry.getValue());

        for (Map.Entry<String, Integer> entry : Variable2.entrySet())
            Zmienna.getVariable().remove(entry.getKey());

    }
}
