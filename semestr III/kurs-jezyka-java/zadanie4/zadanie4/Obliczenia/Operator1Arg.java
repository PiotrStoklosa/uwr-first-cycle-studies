package Obliczenia;

import java.util.Objects;

public abstract class Operator1Arg extends Wyrazenie {
    Wyrazenie a;
    Operator1Arg(Wyrazenie a){
        this.a = a;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Operator1Arg that = (Operator1Arg) o;
        return Objects.equals(a, that.a);
    }
    
}
