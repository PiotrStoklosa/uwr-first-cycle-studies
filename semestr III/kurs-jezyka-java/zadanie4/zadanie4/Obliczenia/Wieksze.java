package Obliczenia;

public class Wieksze extends Operator2Arg {
    public Wieksze(Wyrazenie a, Wyrazenie b){
        super(a,b);
    }
    public int oblicz(){
        return a.oblicz()>b.oblicz() ? 1 : 0;
    }

    @Override
    public String toString() {
        return a.toString() + " > " + b.toString();
    }

}
