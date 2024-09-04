// Using a Object as Lock for synchronization

class MultiThreadOddEvenPrinter {
    private static int counter = 1;
    private static final Object lock = new Object();
    private static final int MAX = 100;

    public static void main(String[] args) {
        Thread oddThread = new Thread(() -> printNumber(true));
        Thread evenThread = new Thread(() -> printNumber(false));
        oddThread.start();
        evenThread.start();
    }

    public static void printNumber(boolean isOdd) {
        synchronized (lock) {
            while (counter <= MAX) {
                if ((counter % 2 != 0) == isOdd) {
                    System.out.println(counter + " " + (isOdd ? "Odd" : "Even"));
                    counter++;
                    lock.notify();
                } else {
                    try {
                        lock.wait();
                    } catch (InterruptedException e) {
                        e.getStackTrace();
                    }
                }
            }
        }
    }
}
