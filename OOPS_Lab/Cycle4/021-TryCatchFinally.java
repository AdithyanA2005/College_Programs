import java.util.Scanner;

class TryCatchFinally {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int result;
    
    System.out.print("Enter number 1: ");
    int num1 = scanner.nextInt();

    System.out.print("Enter number 2: ");
    int num2 = scanner.nextInt();

    try {
      result = num1 / num2; // This will throw an ArithmeticException
      System.out.println("Result: " + result);
    } catch (ArithmeticException e) {
      System.out.println("Error: Division by zero!");
    } finally {
      System.out.println("Program Ended");
    }
  }
}
