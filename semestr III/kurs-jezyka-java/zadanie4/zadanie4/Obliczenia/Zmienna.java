package Obliczenia;

import java.util.Map;
import java.util.Objects;
import java.util.TreeMap;

public class Zmienna extends Wyrazenie{

    private static final Map<String, Integer> Variable = new TreeMap<>();

    private final String name;

    public Zmienna(String name){
        this.name = name;
    }
    public static void add(Zmienna zmienna){
        Variable.put(zmienna.name, 0);
    }
    public static void add(Zmienna zmienna, int wartosc){
        Variable.put(zmienna.name, wartosc);
    }
    public static void replace(String s, int value){ Variable.replace(s, value); }
    public static void czysc(){ Variable.clear(); }
    public int oblicz() {
        return Variable.get(name);
    }
    public static int oblicz(String name) {
        return Variable.get(name);
    }

    public static Map<String, Integer> getVariable() {
        return Variable;
    }


    @Override
    public String toString() {
        return name;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Zmienna zmienna = (Zmienna) o;
        return Objects.equals(Variable.get(name), Variable.get(zmienna.name));
    }

}
