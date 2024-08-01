import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class MultiThreadOddEvenTill100 {
  private static int count = 1;
  private static final int MAX = 100;
  private static final Lock lock = new ReentrantLock();
  private static final Condition oddCondition = lock.newCondition();
  private static final Condition evenCondition = lock.newCondition();
  private static boolean isOdd = true;

  public static void main(String[] args) {
    Thread oddThread = new Thread(() -> printOdd());
    Thread evenThread = new Thread(() -> printEven());

    oddThread.start();
    evenThread.start();
  }

  private static void printOdd() {
    while (count <= MAX) {
      lock.lock();
      try {
        while (!isOdd) {
          oddCondition.await();
        }
        System.out.print(count + " ");
        count++;
        isOdd = false;
        evenCondition.signal();
      } catch (InterruptedException e) {
        e.printStackTrace();
      } finally {
        lock.unlock();
      }
    }
  }

  private static void printEven() {
    while (count <= MAX) {
      lock.lock();
      try {
        while (isOdd) {
          evenCondition.await();
        }
        System.out.print(count + " ");
        count++;
        isOdd = true;
        oddCondition.signal();
      } catch (InterruptedException e) {
        e.printStackTrace();
      } finally {
        lock.unlock();
      }
    }
  }
}
