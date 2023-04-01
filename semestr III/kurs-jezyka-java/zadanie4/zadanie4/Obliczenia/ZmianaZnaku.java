package Obliczenia;

public class ZmianaZnaku extends Operator1Arg{
    public ZmianaZnaku(Wyrazenie a){
        super(a);
    }
    public int oblicz(){
        return (int) (-1*a.oblicz());
    }

    @Override
    public String toString() {
        return "-( " + a.toString() + " )";
    }
}
