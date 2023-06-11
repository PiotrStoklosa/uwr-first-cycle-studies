package lista2.zad7;

import java.util.Random;
import java.util.concurrent.LinkedBlockingQueue;

class Task{
    public Task(int l, int r, int task, Task parent, SynchronizedCounter counter) {
        this.l = l;
        this.r = r;
        this.task = task;
        this.parent = parent;
        this.counter = counter;
    }

    public Task(int task){
        this.task = task;
    }

    public int l;
    public int r;
    public int task;
    public Task parent;
    public SynchronizedCounter counter;
}

class SynchronizedCounter {
    private int c = 0;
    public synchronized int increment() { return ++c;}
}

class MergeSort implements Runnable {
    protected int[] arr;
    protected int[] help_arr;
    protected LinkedBlockingQueue<Task> queue;
    protected int threadsNumber;
    boolean exit = false;

    MergeSort(int[] arr, int[] help_arr, LinkedBlockingQueue<Task> queue, int threadsNumber) {
        this.arr = arr;
        this.help_arr = help_arr;
        this.queue = queue;
        this.threadsNumber = threadsNumber;
    }

    private void merge(Task task) throws InterruptedException {
        int m = (task.l + task.r) / 2;
        int l = task.l;
        int r = task.r;
        int leftArraySize = m - l + 1;
        int rightArraySize = r - m;

        if (r + 1 - l >= 0) System.arraycopy(arr, l, help_arr, l, r + 1 - l);

        int leftCurrent = 0, rightCurrent = 0, resCurrent = l;
        while (leftCurrent < leftArraySize && rightCurrent < rightArraySize) {
            if (help_arr[l + leftCurrent] <= help_arr[m + 1 + rightCurrent]) {
                arr[resCurrent] = help_arr[l + leftCurrent];
                leftCurrent += 1;
            } else {
                arr[resCurrent] = help_arr[m + 1 + rightCurrent];
                rightCurrent += 1;
            }
            resCurrent += 1;
        }

        int begin = leftCurrent < leftArraySize ? l + leftCurrent : m + 1 + rightCurrent;
        int size = leftCurrent < leftArraySize ? leftArraySize - leftCurrent : rightArraySize - rightCurrent;
        System.arraycopy(help_arr, begin, arr, resCurrent, size);

        if (task.parent == null) {
            killThreads();
            return;
        }

        if (task.parent.counter.increment() == 2){
            task.parent.task = 1;
            queue.put(task.parent);
        }
    }

    void killThreads(){
        while(threadsNumber-- > 0) queue.offer(new Task(2));
        exit = true;
    }

    public void sort(Task task) throws InterruptedException {
        if (task.l < task.r) {
            int m = (task.l + task.r) / 2;
            queue.put(new Task(task.l, m, 0, task, new SynchronizedCounter()));
            queue.put(new Task(m+1, task.r, 0, task, new SynchronizedCounter()));
        }
        else {
            if(task.parent == null){ killThreads();}
            else if (task.parent.counter.increment() == 2){
                task.parent.task = 1;
                queue.put(task.parent);
            }
        }
    }

    @Override
    public void run() {
        while(!exit){
            try {
                Task task = queue.take();
                switch (task.task) {
                    case 0 -> sort(task);
                    case 1 -> merge(task);
                    case 2 -> exit = true;
                }
            } catch(Exception ex) {ex.printStackTrace();}
        }
    }
}

public class Main {

    static boolean isSorted(int[] array) {
        for (int i = 0; i < array.length - 1; i++) {
            if (array[i] > array[i + 1])
                return false;
        }
        return true;
    }

    public static void main(String[] args) throws InterruptedException {
        int THREADS = 10;
        int[] arr = new int[10000];
        Random rd = new Random();
        for (int i = 0; i < arr.length; i++) arr[i] = rd.nextInt();

        System.out.println(isSorted(arr));

        LinkedBlockingQueue<Task> queue = new LinkedBlockingQueue<>();
        queue.offer(new Task(0, arr.length-1, 0, null, new SynchronizedCounter()));
        int[] help_arr = new int[arr.length];

        Thread[] threads = new Thread[THREADS];

        for (int i = 0; i < THREADS; i++) threads[i] = new Thread(new MergeSort(arr, help_arr, queue, THREADS));
        for (Thread thread:threads) thread.start();
        for (Thread thread:threads) thread.join();

        System.out.println(isSorted(arr));
    }
}