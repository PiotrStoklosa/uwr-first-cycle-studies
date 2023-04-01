package Obliczenia;

public class WiekszeRowne extends Operator2Arg {
    WiekszeRowne(Wyrazenie a, Wyrazenie b){
        super(a,b);
    }
    public int oblicz(){
        return a.oblicz()>=b.oblicz() ? 1 : 0;
    }

    @Override
    public String toString() {
        return a.toString() + " >= " + b.toString();
    }

}
