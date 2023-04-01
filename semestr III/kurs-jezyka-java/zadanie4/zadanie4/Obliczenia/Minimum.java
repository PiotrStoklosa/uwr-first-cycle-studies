package Obliczenia;

public class Minimum extends Operator2Arg {
    public Minimum(Wyrazenie a, Wyrazenie b){
        super(a,b);
    }
    public int oblicz(){
        return (int) (a.oblicz()<b.oblicz() ? a.oblicz() : b.oblicz());
    }

    @Override
    public String toString() {
        return "min( " + a.toString() + " , " + b.toString() + " )";
    }
}
