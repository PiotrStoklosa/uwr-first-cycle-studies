package struktury;

public class BadStringKeyException extends BadKeyException{
    BadStringKeyException(){
        super("Podano niewłaściwy klucz");
    }
    public String toString(){
        return "Klucz musi zaweirać tylko litery!";
    }
}
