import java.util.Scanner;

class OddOrEven {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    System.out.print("Enter a number: ");
    int num = scanner.nextInt();

    if (num % 2 == 0) System.out.println("It's a even number");
    else System.out.println("It's a odd number");
  }
}
