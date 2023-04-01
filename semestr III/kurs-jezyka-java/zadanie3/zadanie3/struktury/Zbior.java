package struktury;

public abstract class Zbior {

    public abstract Para szukaj (String k) throws Exception;
    public abstract void wstaw (Para p) throws Exception;
    public abstract void usun (String k) throws Exception;
    public abstract double czytaj (String k) throws Exception;
    public abstract void ustaw (Para p) throws Exception;
    public abstract void czysc ();
    public abstract int ile ();

}
