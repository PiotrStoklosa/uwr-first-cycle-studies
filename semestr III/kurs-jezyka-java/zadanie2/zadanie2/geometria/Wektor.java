package geometria;

public final class Wektor {

    public final double dx;
    public final double dy;

    public static Wektor zlozenie(Wektor w1, Wektor w2){
        return new Wektor(w1.getdx() + w2.getdx(), w1.getdy() + w2.getdy());
    }

    public double getdy() {
        return dy;
    }

    public double getdx() {
        return dx;
    }

    public Wektor(double dx, double dy){
        dx = Math.round(dx * 100);
        dx/=100;
        dy = Math.round(dy * 100);
        dy/=100;
        this.dx = dx;
        this.dy = dy;

    }

    @Override
    public String toString() {
        return "Wektor{" +
                "dx=" + dx +
                ", dy=" + dy +
                '}';
    }
}