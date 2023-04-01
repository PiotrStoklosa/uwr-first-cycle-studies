package Obliczenia;

public class Maksimum extends Operator2Arg {
    Maksimum(Wyrazenie a, Wyrazenie b){
        super(a,b);
    }
    public int oblicz(){
        return (int) (a.oblicz()>b.oblicz() ? a.oblicz() : b.oblicz());
    }

    @Override
    public String toString() {
        return "max( " + a.toString() + " , " + b.toString() + " )";
    }
}
