import struktury.Para;
import struktury.ZbiorNaTablicy;
import struktury.ZbiorNaTablicyDynamicznej;

import static java.lang.System.*;

public class Test {
    public static void main(String[] args) throws Exception {
        ZbiorNaTablicy Zbior = new ZbiorNaTablicy(5);

        Zbior.wstaw(new Para("dolar", 3.75));
        Zbior.wstaw(new Para("euro", 4.44));
        out.println("Stworzenie zbioru na tablicy i dodanie dwoch wartosci:");
        out.println(Zbior.toString());

        out.println("\nCzytaj dolar: ");
        out.println(Zbior.czytaj("dolar"));

        Zbior.ustaw(new Para("koronaczeska", 0.17));
        out.println("\nUstawienie elementu koronaczeska na wartosc 0.17:");
        out.println(Zbior.toString());

        out.println("\nUstawienie elementu koronaczeska na wartosc 0.14:");
        Zbior.ustaw(new Para("KoronaCzeska", 0.14));
        out.println(Zbior.toString());

        out.println("\nIlosc elementow zbioru:");
        out.println(Zbior.ile());

        out.println("\nSzukaj euro:");
        out.println(Zbior.szukaj("euro"));

        out.println("\nUsun euro");
        Zbior.usun("euro");
        out.println(Zbior.toString());

        out.println("\nCzysc:");
        Zbior.czysc();
        out.println(Zbior.toString());

        ZbiorNaTablicyDynamicznej ZbiorDynamiczny = new ZbiorNaTablicyDynamicznej();

        ZbiorDynamiczny.wstaw(new Para("dolar", 3.75));
        ZbiorDynamiczny.wstaw(new Para("euro", 4.44));
        out.println("\n\nStworzenie zbioru na tablicy dynamicznej i dodanie dwoch wartosci:");
        out.println(ZbiorDynamiczny.toString());

        ZbiorDynamiczny.wstaw(new Para("koronaczeska", 0.17));
        out.println("\nDodanie trzeciej wartosci:");
        out.println(ZbiorDynamiczny.toString());

        out.println("\nUstawienie elementu koronaczeska na wartosc 0.14:");
        ZbiorDynamiczny.ustaw(new Para("koronaczeska", 0.14));
        out.println(ZbiorDynamiczny.toString());

        out.println("\nUstawienie elementu funtbrytyjski na wartosc 4.97:");
        ZbiorDynamiczny.ustaw(new Para("funtbrytyjski", 4.97));
        out.println(ZbiorDynamiczny.toString());

        out.println("\nUstawienie elementu frankszwajcarski na wartosc 4.12:");
        ZbiorDynamiczny.ustaw(new Para("frankszwajcarski", 4.12));
        out.println(ZbiorDynamiczny.toString());

        out.println("\nUsuniecie elementu frankszwajcarski");
        ZbiorDynamiczny.usun("frankszwajcarski");
        out.println(ZbiorDynamiczny.toString());

        out.println("\nUsuniecie elementu koronaczeska");
        ZbiorDynamiczny.usun("koronaczeska");
        out.println(ZbiorDynamiczny.toString());

        out.println("\nUsuniecie elementu funtbrytyjski");
        ZbiorDynamiczny.usun("funtbrytyjski");
        out.println(ZbiorDynamiczny.toString());

        out.println("\nUsuniecie elementu euro");
        ZbiorDynamiczny.usun("euro");
        out.println(ZbiorDynamiczny.toString());

        out.println("\nCzysc:");
        ZbiorDynamiczny.czysc();
        out.println(ZbiorDynamiczny.toString());
    }
}
