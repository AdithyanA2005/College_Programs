import java.util.Scanner;

class CharacterFrequency {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int count = 0;

    System.out.print("Enter a number: ");
    String str = scanner.nextLine();

    System.out.print("Enter a character: ");
    char ch = scanner.next().charAt(0);

    for (int i = 0; i < str.length(); i++) {
      if (ch == str.charAt(i))
        count++;
    }

    System.out.println("Frequency: " + count);
  }
}
