package Zadanie1;

import static junit.framework.TestCase.assertEquals;
import static org.junit.Assert.assertNotEquals;

public class Test1 {

    @org.junit.Test
    public void Singleton1() {

        Singleton1 first = Singleton1.Instance();
        Singleton1 second = Singleton1.Instance();
        assertEquals(first, second);
    }

    @org.junit.Test
    public void Singleton2() {

        Singleton2 first = Singleton2.Instance();
        Singleton2 second = Singleton2.Instance();


        assertEquals(first, second);

        new Thread(() -> {

            Singleton2 third = Singleton2.Instance();

            assertNotEquals(first, third);

        }).start();


    }

    @org.junit.Test
    public void Singleton3() throws Exception{

        Singleton3 first = Singleton3.Instance();
        Singleton3 second = Singleton3.Instance();
        assertEquals(first, second);

        Thread.sleep(5005);

        Singleton3 third = Singleton3.Instance();
        assertNotEquals(first, third);

    }

}
