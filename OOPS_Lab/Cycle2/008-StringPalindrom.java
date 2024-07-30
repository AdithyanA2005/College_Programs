import java.util.Scanner;

class StringPalindrome {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    boolean isPalindrome = true;

    System.out.print("Enter a string: ");
    String str = scanner.nextLine();
    char[] charArray = str.toCharArray();

    for (int i = 0; i < charArray.length / 2; i++) {
      if (charArray[i] != charArray[charArray.length - i - 1])
        isPalindrome = false;
    }
    
    if (isPalindrome) System.out.println("It's a palindrome");
    else System.out.println("It's is not a palindrome");
  }
}
