package struktury;

public class BadKeyException extends Exception{
    BadKeyException(String s){
        super(s);
    }
    public String toString(){
        return "Podano niewłaściwy klucz";
    }
}
