package Obliczenia;

public class Silnia extends Operator1Arg {

    private static int silnia(int i)
    {
        if (i < 1)
            return 1;
        else
            return i * silnia(i - 1);
    }

    Silnia(Wyrazenie a){
        super(a);
    }
    public int oblicz(){
        return (int) (silnia(a.oblicz()));
    }

    @Override
    public String toString() {
        return " ( " + a.toString() + ")! ";
    }

}
