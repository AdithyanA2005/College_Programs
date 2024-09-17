class ThreadSynchronization {
  private static int counter = 0;
  private static final Object lock = new Object();

  public static void main(String[] args) {
    Runnable increment = () -> {
      for (int i = 1; i <= 100; i++) {
        synchronized (lock) {
          counter++;
        }
      }
    };

    Thread[] threads = {
        new Thread(increment),
        new Thread(increment),
        new Thread(increment),
    };

    for (Thread thread : threads) thread.start();

    try {
      for (Thread thread : threads) thread.join();
    } catch (InterruptedException e) {
      Thread.currentThread().interrupt();
      System.err.println("Thread was interrupted");
    }

    System.out.println("Final counter: " + counter);
  }
}
