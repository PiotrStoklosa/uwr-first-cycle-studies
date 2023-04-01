package geometria;

public class Odcinek {
    private final Punkt x;
    private final Punkt y;
    public Odcinek(Punkt x,Punkt y) throws Exception {

        if (x.equals(y)){
            throw new Exception("Podano identyczne punkty!");
        }
        this.x = x;
        this.y = y;
        x.zaokr();
        y.zaokr();
    }

    public void przesun(Wektor v){
        x.przesun(v);
        y.przesun(v);
    }

    public void obroc(Punkt p, double kat){
        x.obroc(p,kat);
        y.obroc(p,kat);
    }

    public void odbij(Prosta p) throws Exception {
        x.odbij(p);
        y.odbij(p);
    }

    @Override
    public String toString() {
        return "Odcinek{" +
                "x=" + x +
                ", y=" + y +
                '}';
    }
}
