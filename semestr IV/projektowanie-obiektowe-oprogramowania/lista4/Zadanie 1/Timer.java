package Zadanie1;

import static java.lang.Thread.sleep;

public class Timer implements Runnable{

    @Override
    public void run() {
        try {
            sleep(5000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
