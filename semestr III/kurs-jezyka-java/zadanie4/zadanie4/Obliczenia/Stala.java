package Obliczenia;

import java.util.Map;
import java.util.Objects;
import java.util.TreeMap;

public class Stala extends Wyrazenie implements Obliczalny {
    private static Map<String, Double> Constant = new TreeMap<>();

    private String name;

    public Stala(String name){
        this.name = name;
    }
    public static void fill(){
        Constant.put("Jeden", 1.0);
        Constant.put("Zero", 0.0);
        Constant.put("-Jeden", -1.0);
    }
    public static void add(String name, Double value){
        Constant.put(name, value);
    }
    public int oblicz() {
        return Constant.get(name).intValue();
    }

    @Override
    public String toString() {
        return name;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Stala stala = (Stala) o;
        return Objects.equals(Constant.get(name).intValue(), Constant.get(stala.name).intValue());
    }

}
