package Obliczenia;

import java.util.Objects;

public class Liczba extends Wyrazenie{
    double a;
    public Liczba(double a){
        this.a = a;
    }

    @Override
    public int oblicz() {
        return (int)a;
    }

    @Override
    public String toString() {
        return String.valueOf(a);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Liczba liczba = (Liczba) o;
        return Double.compare(liczba.a, a) == 0;
    }

}
