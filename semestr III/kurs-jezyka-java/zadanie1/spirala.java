//Piotr Stokłosa Zadanie1

public class Spirala {

    private static final boolean[] sieve = new boolean[40001];

    static boolean ifPrimary(int number){

        return !sieve[number];

    }
    
    static void fillingTheSieve(){

        sieve[0] = true;
        sieve[1] = true;

        for (int i = 2; i < 40001; i++)
            if (!sieve[i])
                for (int j = i * i; j < 40001; j += i)
                    sieve[j] = true;
    }

    static void fillingTheSpiral(int[][] spiral, int n){

        int start = n / 2;
        int max = 2; // (maks / 2) oznacza ile powinien algorytm przypisac liczb w jednej lini
        int currentMax = 1; // oznacza ile jeszcze trzeba przypisac liczb przed zmiana kierunku
        int currentx = n % 2 == 0 ? start - 1 : start; // miejsce od ktorego zaczynamy
        int currenty = start; // miejsce od ktorego zaczynamy
        int direction = 0; // wschod = 0, polnoc = 1, zachod = 2; poludnie = 3

        for (int i = 1; i <= n * n; i++){

            spiral[currenty][currentx] = i;

            if (currentMax == 0){ // jesli prawda trzeba zmienic kierunek

                max++;
                currentMax = max / 2;
                direction++;

                if (direction == 4)
                    direction = 0;
            }

            if (direction == 0) // zmiana parametru zaleznie od kierunku w ktorym idzie algorytm
                currentx++;

            if (direction == 1)
                currenty--;

            if (direction == 2)
                currentx--;

            if (direction == 3)
                currenty++;

            currentMax--;

        }
    }

    static void fillingWithZeros(int[][] spiral, int n){

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (!ifPrimary(spiral[i][j]))
                    spiral[i][j] = 0;

    }
    
    static void printingTheSpiral(int[][] spiral, int n){

        for (int i=0; i<n; i++) {

            for (int j = 0; j < n; j++)
                if (spiral[i][j] != 0)
                    System.out.print("* ");
                else
                    System.out.print("  ");

            System.out.print('\n');

        }

    }

    public static void main(String[] args){

        int size = Integer.parseInt(args[0]);

        if (size < 2 || size > 200)
            throw new IllegalArgumentException("parametr spoza zakresu 2...200");

        int[][] spiral = new int[size][size];

        fillingTheSieve();
        fillingTheSpiral(spiral, size);
        fillingWithZeros(spiral, size);
        printingTheSpiral(spiral, size);
    }
}
