package lista2.zad5;

class ParallelPrefSum implements Runnable {

    protected int[] arr;
    protected int[] arrNew;
    protected int id;
    protected static final int THREADS = 2;
    protected int currentTwoPower = 0;

    public ParallelPrefSum(int[] arr, int[] arrNew, int id, int currentTwoPower) {
        this.arr = arr;
        this.id = id;
        this.arrNew = arrNew;
        this.currentTwoPower = currentTwoPower;
    }

    @Override
    public void run() {
        for (int i = id; i < arr.length; i += THREADS) {
            if (i < (1 << currentTwoPower)) {
                arrNew[i] = arr[i];
            } else {
                arrNew[i] = arr[i] + arr[i - (1 << currentTwoPower)];
            }
        }
    }
}

public class PrefSum {
    public static void main(String[] args) {

        int arr[] = {1,2,3,4,5,6,7,8,9};
        int[] newArr = new int[arr.length];
        boolean flag = true;
        Thread[] threads = new Thread[ParallelPrefSum.THREADS];

        for (int i = 0; (1 << i) <= arr.length; i++) {
            flag = !flag;
            for (int j = 0; j < ParallelPrefSum.THREADS; j++) {
                ParallelPrefSum parallelPrefSum;
                if(!flag)
                    parallelPrefSum = new ParallelPrefSum(arr, newArr, j, i);
                else
                    parallelPrefSum = new ParallelPrefSum(newArr, arr, j, i);
                threads[j] = new Thread(parallelPrefSum);
                threads[j].start();
            }
            for (int j = 0; j < ParallelPrefSum.THREADS; j++) {
                try {
                    threads[j].join();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }

        if (!flag)
            for (int i : newArr)
                System.out.print(i + " ");
        else
            for (int i : arr)
                System.out.print(i + " ");
    }
}
