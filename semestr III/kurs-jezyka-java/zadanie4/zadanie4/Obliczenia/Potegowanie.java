package Obliczenia;

import static java.lang.StrictMath.pow;

public class Potegowanie extends Operator2Arg {
    public Potegowanie(Wyrazenie a, Wyrazenie b){
        super(a,b);
    }
    public int oblicz(){
        return (int) (pow(a.oblicz(),b.oblicz()));
    }

    @Override
    public String toString() {
        return " ( " + a.toString() + " ) ^ (" + b.toString() + " ) ";
    }

}
