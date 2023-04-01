package Obliczenia;

import java.util.Objects;

public abstract class Operator2Arg extends Operator1Arg{
    Wyrazenie b;
    Operator2Arg(Wyrazenie a,Wyrazenie b){
        super(a);
        this.b = b;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        if (!super.equals(o)) return false;
        Operator2Arg that = (Operator2Arg) o;
        return Objects.equals(b, that.b);
    }

}
