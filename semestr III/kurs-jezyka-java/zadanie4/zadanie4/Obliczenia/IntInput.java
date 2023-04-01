package Obliczenia;

import java.util.Scanner;

public class IntInput extends Instrukcja{

    Scanner scan = new Scanner(System.in);
    private int WczytanaLiczba;
    private String name;


    public IntInput(String name) throws Exception {
        if (name==null)
            throw new Exception("Oczekiwano nazwy, dostano null!");

        this.name = name;
    }

    @Override
    public void wykonaj() throws Exception {
        Przypisz przypisz = new Przypisz(name,new Liczba(scan.nextInt()));
        przypisz.wykonaj();
    }
}
