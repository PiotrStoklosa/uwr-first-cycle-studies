package Obliczenia;

public class Modulo extends Operator2Arg {
    public Modulo(Wyrazenie a, Wyrazenie b){
        super(a,b);
    }
    public int oblicz(){
        return (int) (a.oblicz()%b.oblicz());
    }

    @Override
    public String toString() {
        return " ( " + a.toString() + " ) % (" + b.toString() + " ) ";
    }

}

