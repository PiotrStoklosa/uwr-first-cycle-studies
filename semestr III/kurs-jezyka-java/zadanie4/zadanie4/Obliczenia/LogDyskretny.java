package Obliczenia;

import static java.lang.Math.log;

public class LogDyskretny extends Operator2Arg {
    public LogDyskretny(Wyrazenie a, Wyrazenie b){
        super(a,b);
    }
    public int oblicz(){
        return (int) (log(b.oblicz())/log(a.oblicz()));
    }

    @Override
    public String toString() {
        return "log_[" + a.toString() + "] ( " + b.toString() + " )";
    }
}
