package struktury;

public class LackOfStringException extends BadKeyException{
    LackOfStringException(){
        super("Podano niewłaściwy klucz");
    }
    public String toString(){
        return "Klucz nie może być pusty/wartoscia null";
    }
}
