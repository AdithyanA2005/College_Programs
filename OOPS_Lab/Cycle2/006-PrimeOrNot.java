import java.util.Scanner;

class PrimeOrNot {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    boolean isPrime = true;

    System.out.print("Enter a number: ");
    int num = scanner.nextInt();

    if (num <= 1) {
      isPrime = false;
    } else {
      for (int i = 2; i <= Math.sqrt(num); i++) {
        if (num % i == 0) {
          isPrime = false;
          break;
        }
      }
    }

    if (isPrime) System.out.println("It's a prime number");
    else System.out.println("It's not a prime number");
  }
}
