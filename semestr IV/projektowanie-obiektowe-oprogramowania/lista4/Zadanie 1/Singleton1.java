package Zadanie1;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Singleton1 {

    private static Singleton1 instance;
    private static final Lock lock = new ReentrantLock();

    public static Singleton1 Instance(){

        if (instance == null){

            lock.lock();
            if (instance == null){
                instance = new Singleton1();
            }
            lock.unlock();

        }

        return instance;
    }

}
