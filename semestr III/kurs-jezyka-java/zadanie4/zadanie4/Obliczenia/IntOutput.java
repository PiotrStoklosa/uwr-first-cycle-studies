package Obliczenia;

public class IntOutput extends Instrukcja{

    int wartosc;

    public IntOutput(int wartosc){

        this.wartosc=wartosc;
    }

    @Override
    public void wykonaj() {
        System.out.println(wartosc);
    }
}
