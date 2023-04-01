package Obliczenia;

public abstract class Wyrazenie implements Obliczalny{
    public static double suma (Wyrazenie... wyr) {
        double result = 0;
        for (Wyrazenie w : wyr)
            result += w.oblicz();
        return result;
    }
    public static double iloczyn (Wyrazenie... wyr) {
        double result = 1;
        for (Wyrazenie w : wyr)
            result *= w.oblicz();
        return result;
    }
}
