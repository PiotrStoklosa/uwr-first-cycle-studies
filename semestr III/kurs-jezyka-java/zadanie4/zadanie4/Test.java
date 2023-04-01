import Obliczenia.*;
import Obliczenia.Wyrazenie;

public class Test {

    public static void zad2(){

        Stala.fill();

        Zmienna.add(new Zmienna("x"),2);
        Zmienna.add(new Zmienna("y"),3);


        Wyrazenie w1 = new Dodawanie(new Liczba(3),new Liczba(5));


        Wyrazenie w2 = new Mnozenie(
                new ZmianaZnaku(
                        new Odejmowanie(
                                new Liczba(2),
                                new Zmienna("x"))),
                new Liczba(7));

        System.out.println("(3 * 11 - 1) / (7 + 5)");

        Wyrazenie w3 = new Dzielenie(
                new Odejmowanie(
                        new Mnozenie(
                                new Liczba(3),
                                new Liczba(11)),
                        new Stala("Jeden")),
                new Dodawanie(
                        new Liczba(7),
                        new Liczba(5)));

        System.out.println("min((x + 13) * x, (1 - x) mod 2)");

        Wyrazenie w4 = new Minimum(
                new Mnozenie(
                        new Dodawanie(
                                new Zmienna("x"),
                                new Liczba(13)),
                        new Zmienna("x")),
                new Modulo(
                        new Odejmowanie(
                                new Stala("Jeden"),
                                new Zmienna("x")),
                        new Liczba(2)));

        System.out.println("2 ^ 5 + x * log(2, y) < 20");

        Wyrazenie w5 = new Mniejsze(
                new Dodawanie(
                        new Potegowanie(
                                new Liczba(2),
                                new Liczba(5)),
                        new Mnozenie(
                                new Zmienna("x"),
                                new LogDyskretny(
                                        new Liczba(2),
                                        new Zmienna("y")))),
                new Liczba(20));

        System.out.println(w1.toString());
        System.out.println(w1.oblicz());
        System.out.println(w2.toString());
        System.out.println(w2.oblicz());
        System.out.println(w3.toString());
        System.out.println(w3.oblicz());
        System.out.println(w4.toString());
        System.out.println(w4.oblicz());
        System.out.println(w5.toString());
        System.out.println(w5.oblicz());
        System.out.println();
    }

    public static void zad3() throws Exception {

        Zmienna.czysc();

        InstrukcjaBlokowa czyPierwsza = new InstrukcjaBlokowa (
                new DeklaracjaZmiennej(new Zmienna("n")),
                new IntInput("n"),
                new JezeliWPrzeciwnymWypadku(
                        new Mniejsze(
                                new Zmienna("n"),
                                new Liczba(2)),
                        new InstrukcjaBlokowa(
                                new IntOutput(0)),
                        new InstrukcjaBlokowa(
                                new DeklaracjaZmiennej(new Zmienna("p")),
                                new Przypisz("p",new Liczba(2)),
                                new DeklaracjaZmiennej(new Zmienna("wyn")),
                                new Petla(
                                        new MniejszeRowne(
                                                new Mnozenie(
                                                        new Zmienna("p"),
                                                        new Zmienna("p")),
                                                new Zmienna("n")),

                                        new InstrukcjaBlokowa(
                                                new Jezeli(
                                                        new Rowne(new Modulo(new Zmienna("n"),new Zmienna("p")),new Liczba(0)),
                                                        new InstrukcjaBlokowa(
                                                                new Przypisz("wyn",new Zmienna("p")),
                                                                new Przypisz("p",new Zmienna ("n")))),
                                                new Przypisz("p",new Dodawanie(new Zmienna("p"),new Liczba(1)))

                                        )),
                                new JezeliWPrzeciwnymWypadku(
                                        new Wieksze(
                                                new Zmienna("wyn"),
                                                new Liczba(0)),
                                        new InstrukcjaBlokowa(
                                                new IntOutput(0)),
                                        new InstrukcjaBlokowa(
                                                new IntOutput(1))
                                )
                        )
                ));

        czyPierwsza.wykonaj();
    }


    public static void main(String[] args) throws Exception {

       // zad2();
        zad3();

    }
}
