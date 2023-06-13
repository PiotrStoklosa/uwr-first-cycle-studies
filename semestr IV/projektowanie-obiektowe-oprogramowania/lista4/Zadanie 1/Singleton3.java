package Zadanie1;

public class Singleton3 {

    private static Singleton3 instance;

    public static Thread timer = new Thread(new Timer());

    public static Singleton3 Instance(){

        if (!timer.isAlive()){
            timer = new Thread(new Timer());
            timer.start();
            instance = new Singleton3();
        }
        return instance;
    }

}
