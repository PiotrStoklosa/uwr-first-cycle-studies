package geometria;

public class Punkt {
    private double x,y;
    public Punkt(double x, double y){
        this.x = x;
        this.y = y;
        zaokr();
    }

    public void zaokr(){
        x = Math.round(x * 100);
        x/=100;
        y = Math.round(y * 100);
        y/=100;
    }

    public void przesun(Wektor v){
        x+=v.getdx();
        y+=v.getdy();
        zaokr();
    }

    double getX(){
        return x;
    }
    double getY(){
        return y;
    }

    public void obroc(Punkt p, double kat){
        double cos_kat = Math.round(Math.cos(Math.toRadians(kat)) * 100) ;
        double sin_kat = Math.round(Math.sin(Math.toRadians(kat)) * 100) ;
        cos_kat/=100;
        sin_kat/=100;
        double newx = cos_kat * (getX() - p.getX()) - sin_kat * (getY() - p.getY()) + p.getX();
        double newy = sin_kat * (getX() - p.getX()) + cos_kat * (getY() - p.getY()) + p.getY();
        x = newx;
        y = newy;
        zaokr();
    }

    public void odbij(Prosta p) throws Exception {
        double a1, b1, c1; // prosta prostopadła przechodzaca przez punkt
        if (p.geta()==0){
            double difference = getY() + p.getc()/p.getb();
            y -= 2 * difference;
        }
        else{
            a1 = (-1) * p.getb()/p.geta();
            b1 = 1;
            c1 = (-1) * (a1 * x + y);
            Prosta prostopadla = new Prosta(a1,b1,c1);
            Punkt przeciecie = Prosta.przeciecie(p, prostopadla);
            double x_difference = x - przeciecie.getX();
            double y_difference = y - przeciecie.getY();
            x-= 2 * x_difference;
            y-= 2 * y_difference;

        }
        zaokr();
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Punkt punkt = (Punkt) o;
        return Double.compare(punkt.x, x) == 0 &&
                Double.compare(punkt.y, y) == 0;
    }

    @Override
    public String toString() {
        return "Punkt{" +
                "x=" + x +
                ", y=" + y +
                '}';
    }
}
