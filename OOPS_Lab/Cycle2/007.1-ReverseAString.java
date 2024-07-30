import java.util.Scanner;

class ReverseAString1 {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    System.out.print("Enter a string: ");
    String str = scanner.nextLine();

    StringBuilder buildStr = new StringBuilder(str);
    buildStr.reverse();

    System.out.println("Reverse: " + buildStr.toString());
  }
}
