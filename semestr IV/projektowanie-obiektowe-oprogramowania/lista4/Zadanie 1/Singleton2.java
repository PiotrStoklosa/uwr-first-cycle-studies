package Zadanie1;

public class Singleton2 {

    private static final ThreadLocal<Singleton2> instance = ThreadLocal.withInitial(Singleton2::new);

    public static Singleton2 Instance(){

        return instance.get();
    }
}
