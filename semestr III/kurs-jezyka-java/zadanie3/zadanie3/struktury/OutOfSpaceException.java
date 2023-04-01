package struktury;

public class OutOfSpaceException extends Exception{

    OutOfSpaceException(){
            super("Zabrakło miejsca w zbiorze!");
    }
    public String toString(){
        return "Zabrakło miejsca w zbiorze!";
    }
}
