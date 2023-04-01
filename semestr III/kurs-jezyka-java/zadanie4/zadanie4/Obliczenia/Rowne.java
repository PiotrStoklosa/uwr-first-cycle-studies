package Obliczenia;

import static java.lang.StrictMath.pow;

public class Rowne extends Operator2Arg{
    public Rowne(Wyrazenie a, Wyrazenie b){
        super(a,b);
    }
    public int oblicz(){
        return (int) (a.oblicz()==b.oblicz() ? 1 : 0);
    }

    @Override
    public String toString() {
        return a.toString() + " = " + b.toString();
    }

}
