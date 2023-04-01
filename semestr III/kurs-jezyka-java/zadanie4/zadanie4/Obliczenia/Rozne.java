package Obliczenia;

public class Rozne extends Operator2Arg {
    Rozne(Wyrazenie a, Wyrazenie b){
        super(a,b);
    }
    public int oblicz(){
        return (int) (a.oblicz()!=b.oblicz() ? 1 : 0);
    }

    @Override
    public String toString() {
        return a.toString() + " != " + b.toString();
    }

}
