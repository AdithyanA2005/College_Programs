import java.util.Scanner;

class ReverseAString2 {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    System.out.print("Enter a string: ");
    String str = scanner.nextLine();
    char[] charArray = str.toCharArray();

    for (int i = 0; i < charArray.length / 2; i++) {
      char temp = charArray[i];
      charArray[i] = charArray[charArray.length - i - 1];
      charArray[charArray.length - i - 1] = temp;
    }

    
    System.out.println("Reverse: " + new String(charArray));
  }
}
