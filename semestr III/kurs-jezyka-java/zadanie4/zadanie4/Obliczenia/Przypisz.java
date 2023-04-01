package Obliczenia;

public class Przypisz extends Instrukcja{

    private String name;
    private Wyrazenie w;

    public Przypisz(String name, Wyrazenie w) throws Exception {

        if (name==null || w==null)
            throw new Exception("Oczekiwano nazwy oraz wyrazenie, dostano null!");

        this.name=name;
        this.w=w;
    }



    @Override
    public void wykonaj() {
        Zmienna.replace(name,w.oblicz());
    }
}
