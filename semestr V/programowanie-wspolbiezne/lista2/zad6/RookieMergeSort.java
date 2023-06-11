package lista2.zad6;

import java.util.Random;
import java.util.concurrent.ConcurrentLinkedQueue;

import static java.lang.Thread.sleep;

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
    public int task; // 0 - sort 1 - merge 2 - exit
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
    protected ConcurrentLinkedQueue<Task> queue;
    protected int threadsNumber;
    boolean exit = false;

    MergeSort(int[] arr, int[] help_arr, ConcurrentLinkedQueue<Task> queue, int threadsNumber) {
        this.arr = arr;
        this.help_arr = help_arr;
        this.queue = queue;
        this.threadsNumber = threadsNumber;
    }

    private void merge(Task task) {
        int m = (task.l + task.r) / 2;
        int l = task.l;
        int r = task.r;
        int leftArraySize = m - l + 1;
        int rightArraySize = r - m;

        // przepisanie do tablicy pomocniczej
        if (r + 1 - l >= 0) System.arraycopy(arr, l, help_arr, l, r + 1 - l);

        // merging
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
        // finishing
        int begin = leftCurrent < leftArraySize ? l + leftCurrent : m + 1 + rightCurrent;
        int size = leftCurrent < leftArraySize ? leftArraySize - leftCurrent : rightArraySize - rightCurrent;
        System.arraycopy(help_arr, begin, arr, resCurrent, size);

        // maybe add parent to queue if not finish threads
        if (task.parent == null) {
            killThreads();
            return;
        }

        if (task.parent.counter.increment() == 2){
            task.parent.task = 1;
            queue.offer(task.parent);
        }
    }

    void killThreads(){
        while(threadsNumber-- > 0) queue.offer(new Task(2));
        exit = true;
    }

    public void sort(Task task) {
        if (task.l < task.r) {
            int m = (task.l + task.r) / 2;
            queue.offer(new Task(task.l, m, 0, task, new SynchronizedCounter()));
            queue.offer(new Task(m+1, task.r, 0, task, new SynchronizedCounter()));
        }
        else {
            if(task.parent == null){ killThreads();}
            if (task.parent.counter.increment() == 2){
                task.parent.task = 1;
                queue.offer(task.parent);
            }
        }

    }

    @Override
    public void run() {
        while(!exit){
            Task task = queue.poll();
            if (task == null){
                try {sleep(5);}
                catch (Exception ex) {ex.printStackTrace();}
            }
            else switch (task.task) {
                case 0 -> sort(task);
                case 1 -> merge(task);
                case 2 -> exit = true;
            }
        }
    }
}

public class RookieMergeSort {

    static boolean isSorted(int[] array) { // https://www.baeldung.com/java-check-sorted-array
        for (int i = 0; i < array.length - 1; i++) {
            if (array[i] > array[i + 1])
                return false;
        }
        return true;
    }

    public static void main(String[] args) throws InterruptedException {
        int THREADS = 4;
        int[] arr = new int[1000000];
        Random rd = new Random();
        for (int i = 0; i < arr.length; i++) arr[i] = rd.nextInt(); // storing random integers in an array

        ConcurrentLinkedQueue<Task> queue = new ConcurrentLinkedQueue<>();
        queue.offer(new Task(0, arr.length-1, 0, null, new SynchronizedCounter()));
        int[] help_arr = new int[arr.length];

        Thread[] threads = new Thread[THREADS];

        for (int i = 0; i < THREADS; i++) threads[i] = new Thread(new MergeSort(arr, help_arr, queue, THREADS));
        for (Thread thread:threads) thread.start();
        for (Thread thread:threads) thread.join();

        System.out.println(isSorted(arr));
    }
}
