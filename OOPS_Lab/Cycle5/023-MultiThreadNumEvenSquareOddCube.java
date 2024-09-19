import java.util.Random;
import java.util.function.Consumer;
import java.util.function.Predicate;

class MultiThreadNumEvenSquareOddCube {
  private static volatile int num = -1;
  private static final Object lock = new Object();

  public static void main(String[] args) {
    Random random = new Random();

    // Thread 1: Generates a number and display it
    new Thread(() -> {
      while (true) {
        synchronized (lock) {
          num = random.nextInt(100); // 0 - 99
          System.out.println("\nNumber: " + num);
          lock.notifyAll();
        }
        sleep(1000);
      }
    }).start();

    // Thread 2: Display square if number is even
    new Thread(() -> process(n -> n % 2 == 0, n -> System.out.println("Square: " + (n * n)))).start();

    // Thread 3: Display cube if number is odd
    new Thread(() -> process(n -> n % 2 != 0, n -> System.out.println("Cube: " + (n * n * n)))).start();
  }

  private static void process(Predicate<Integer> condition, Consumer<Integer> action) {
    while (true) {
      synchronized (lock) {
        try {
          while (num == -1 || !condition.test(num)) {
            lock.wait();
          }
          action.accept(num);
          num = -1;
        } catch (InterruptedException e) {
          Thread.currentThread().interrupt();
        }
      }
    }
  }

  private static void sleep(int millis) {
    try {
      Thread.sleep(millis);
    } catch (InterruptedException e) {
      Thread.currentThread().interrupt();
    }
  }
}
