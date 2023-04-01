package struktury;

public class LackOfPairException extends Exception{

    LackOfPairException(){
        super("Nie znaleziono odpowiedniej pary!");
    }
    public String toString(){
        return "Nie znaleziono odpowiedniej pary!";
    }
}
