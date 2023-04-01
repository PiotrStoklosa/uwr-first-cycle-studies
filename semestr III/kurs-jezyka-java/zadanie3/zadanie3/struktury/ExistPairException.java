package struktury;

public class ExistPairException extends Exception{
    ExistPairException(){
        super("Zbior juz posiada podany klucz!");
    }
    public String toString(){
        return "Zbior juz posiada podany klucz!";
    }
}
