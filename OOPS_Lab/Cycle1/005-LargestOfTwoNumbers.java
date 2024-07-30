import java.util.Scanner;

class LargestOfTwoNumbers { 
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    System.out.print("Enter number 1: ");
    int num1 = scanner.nextInt();

    System.out.print("Enter number 2: ");
    int num2 = scanner.nextInt();

    System.out.println((num1 > num2 ? num1 : num2) + " is the largest");
  }
}
