package Obliczenia;

public class Odejmowanie extends Operator2Arg {
    public Odejmowanie(Wyrazenie a, Wyrazenie b){
        super(a,b);
    }
    public int oblicz(){
        return (int) (a.oblicz()-b.oblicz());
    }

    @Override
    public String toString() {
        return a.toString() + " - ( " + b.toString() + " )";
    }

}