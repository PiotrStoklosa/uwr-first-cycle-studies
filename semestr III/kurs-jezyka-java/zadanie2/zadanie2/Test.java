import geometria.*;

public class Test {
    public static void main(String[] args) throws Exception {
        Punkt p = new Punkt (1,1);
        Wektor v = new Wektor (2,3);
        Wektor v2 = new Wektor (5,-1);
        Prosta x = new Prosta (1, -1, 0);

        //Trojkat
        System.out.println("Stworzenie trojkata o punktach x(0,0), y(1,1), z(1,0)\n");
        Trojkat trojkat = new Trojkat (new Punkt(0,0),new Punkt(1,1),new Punkt(1,0));
        trojkat.przesun(v);
        System.out.println("Trojkat po przesunieciu o wektor v(2,3): ");
        System.out.println(trojkat.toString());

        trojkat.obroc(p,90);
        System.out.println("\nTrojkat po obroceniu o kat 90 stopni, wzgledem punktu p(1,1):");
        System.out.println(trojkat.toString());

        trojkat.odbij(x);
        System.out.println("\nTrojkat po odbiciu wzgledem prostej x(x - y + 0 = 0)): ");
        System.out.println(trojkat.toString());

        //Odcinek
        System.out.println("\n\nStworzenie odcinka o punktach x(0,0), y(1,1)\n");
        Odcinek odcinek = new Odcinek (new Punkt(0,0),new Punkt(1,1));
        odcinek.przesun(v);
        System.out.println("Odcinek po przesunieciu o wektor v(2,3): ");
        System.out.println(odcinek.toString());

        odcinek.obroc(p,90);
        System.out.println("\nOdcinek po obroceniu o kat 90 stopni, wzgledem punktu p(1,1):");
        System.out.println(odcinek.toString());

        odcinek.odbij(x);
        System.out.println("\nOdcinek po odbiciu wzgledem prostej x(x - y + 0 = 0)): ");
        System.out.println(odcinek.toString());

        //Punkt
        System.out.println("\n\nStworzenie punktu a(2,2)\n");
        Punkt punkt = new Punkt (2,2);

        punkt.przesun(v);
        System.out.println("Punkt po przesunieciu o wektor v(2,3): ");
        System.out.println(punkt.toString());

        punkt.obroc(p,90);
        System.out.println("\nPunkt po obroceniu o kat 90 stopni, wzgledem punktu p(1,1):");
        System.out.println(punkt.toString());

        punkt.odbij(x);
        System.out.println("\nPunkt po odbiciu wzgledem prostej x(x - y + 0 = 0)): ");
        System.out.println(punkt.toString());

        //wektor
        System.out.println("\n\nZlozenie wektora v(2,3) z wektorem v2(5,-1):");
        System.out.println(Wektor.zlozenie(v,v2).toString());

        //prosta

        Prosta prosta1 = new Prosta (1,-1,0);
        Prosta prosta2 = new Prosta (1,1,2);

        System.out.println("\n\nProsta x-y+0=0 po przesunieciu o wektor v(2,3): ");
        System.out.println(Prosta.przesuwanie(prosta1,v).toString());

        System.out.println("\nSprawdzenie czy prosta x-y+0=0 jest prostopadla do prostej x+y+2=0:");
        if (Prosta.prostopadle(prosta1,prosta2)){
            System.out.println("Proste są prostopadłe, punkt przeciecia:");
            System.out.println(Prosta.przeciecie(prosta1,prosta2));
        }

        System.out.println("\nSprawdzenie czy prosta x-y+0=0 jest rownolegla do prostej x+y+2=0:");
        if (Prosta.rownolegle(prosta1,prosta2))
            System.out.println("Proste są rownolegle");
        else
            System.out.println("Proste nie są rownolegle");

    }
}