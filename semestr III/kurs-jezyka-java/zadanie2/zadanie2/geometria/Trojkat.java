package geometria;

public class Trojkat {
    private final Punkt x;
    private final Punkt y;
    private final Punkt z;

    public Trojkat(Punkt x, Punkt y, Punkt z) throws Exception {

        if (x.equals(y) || x.equals(z) || y.equals(z)){
            throw new Exception("Podano co najmniej dwa identyczne punkty!");
        }

        this.x = x;
        this.y = y;
        this.z = z;

        //rownanie kierunkowe prostej
        double a = (x.getY() - y.getY())/(x.getX() - y.getX());
        double b = x.getY() - a * x.getX();

        if (a * z.getX() + b == z.getY()) {
            throw new Exception("Podane pukty są współliniowe!");
        }

    }

    public void przesun(Wektor v){
        x.przesun(v);
        y.przesun(v);
        z.przesun(v);
    }

    public void obroc(Punkt p, double kat){
        x.obroc(p,kat);
        y.obroc(p,kat);
        z.obroc(p,kat);
    }

    public void odbij(Prosta p) throws Exception {
        x.odbij(p);
        y.odbij(p);
        z.odbij(p);
    }

    @Override
    public String toString() {
        return "Trojkat{" +
                "x=" + x +
                ", y=" + y +
                ", z=" + z +
                '}';
    }
}
