package struktury;

import java.util.Objects;

public class Para {

    public final String klucz;
    private double wartosc;

    public Para(String klucz, double wartosc) throws Exception {

        if (klucz.equals(""))
            throw new LackOfStringException();

        this.klucz = klucz.toLowerCase();

        if (klucz.matches("[a‑z]+"))
            throw new BadStringKeyException();

        this.wartosc = wartosc;
    }

    @Override
    public String toString() {
        return "Para{" +
                "klucz='" + klucz + '\'' +
                ", wartość=" + wartosc +
                '}';
    }


    @Override
    public boolean equals(Object o) {

        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Para para = (Para) o;
        return klucz.equals(para.klucz);

    }

    @Override
    public int hashCode() {
        return Objects.hash(klucz);
    }

    public double getWartosc() {
        return wartosc;
    }

    public void setWartosc(double wartosc) {
        this.wartosc = wartosc;
    }
}
