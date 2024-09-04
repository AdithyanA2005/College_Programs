// Using Semaphore

import java.util.concurrent.Semaphore;

public class MultiThreadOddEvenPrinter {
    private static int counter = 1;
    private static final Semaphore semaphore = new Semaphore(1); // Optional: use semaphore for explicit control
    private static final int MAX = 100;

    public static void main(String[] args) {
        Thread oddThread = new Thread(() -> printNumbers(false));
        Thread evenThread = new Thread(() -> printNumbers(true));
        oddThread.start();
        evenThread.start();
    }

    public static void printNumbers(boolean isEven) {
        try {
            while (counter <= MAX) {
                semaphore.acquire(); // Optional: acquire permit using semaphore

                if ((counter % 2 == 0) == isEven) {
                    System.out.println(counter + " " + (isEven ? "Even" : "Odd"));
                    counter++;
                }

                semaphore.release(); // Optional: release permit using semaphore
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
