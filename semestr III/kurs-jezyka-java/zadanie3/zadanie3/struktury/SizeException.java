package struktury;

public class SizeException extends Exception{
    SizeException(){
        super("Rozmiar nie może być mniejszy niż 2!");
    }
    public String toString(){
        return "Rozmiar nie może być mniejszy niż 2!";
    }
}
