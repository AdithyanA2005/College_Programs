import java.util.*;

class Main {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    System.out.print("Enter line of integers: ");
    String s = sc.nextLine();

    StringTokenizer st = new StringTokenizer(s," ");
    int sum = 0;

    while(st.hasMoreTokens()) {
      String token = st.nextToken();
      int n = Integer.parseInt(token);
      sum += n;
    }

    System.out.println("The sum: " + sum);
  }
}
