package geometria;

public final class Prosta {

    public final double a;
    public final double b;
    public final double c;

    public static Prosta przesuwanie(Prosta p, Wektor w){
        Prosta result;
        if (p.getb()!=0)
            result = new Prosta(p.geta() - w.getdx() * p.getb(), p.getb(), p.getc() - w.getdy() * p.getb());
        else
            result = new Prosta (p.geta(), 0, p.getc() - w.getdx() * p.geta());

        return result;
    }

    public static boolean rownolegle(Prosta p1, Prosta p2){
        return p1.geta() * p2.getb() == p2.geta() * p1.getb();
    }

    public static boolean prostopadle(Prosta p1, Prosta p2){
        return p1.geta() * p2.geta() == (-1) * p1.getb() * p2.getb();
    }

    public static Punkt przeciecie(Prosta p1, Prosta p2) throws Exception {
        if (rownolegle(p1,p2))
            throw new Exception("Podano dwie proste rownolegle!");
        //z metody wyznacznikow
        double wx = p2.getc() * p1.getb() - p1.getc() * p2.getb();
        double wy = p2.geta() * p1.getc() - p1.geta() * p2.getc();
        double w = p1.geta() * p2.getb() - p2.geta() * p1.getb();
        return new Punkt (wx/w,wy/w);
    }

    public Prosta(double a, double b, double c){
        this.a = a;
        this.b = b;
        this.c = c;
    }

    public double geta() {
        return a;
    }

    public double getb() {
        return b;
    }

    public double getc() {
        return c;
    }

    @Override
    public String toString() {
        return "Prosta{" +
                "a=" + a +
                ", b=" + b +
                ", c=" + c +
                '}';
    }
}
