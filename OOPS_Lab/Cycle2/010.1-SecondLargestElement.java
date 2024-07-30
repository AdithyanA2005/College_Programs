import java.util.Scanner;
import java.util.Arrays;

class SecondLargestElement1 {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    System.out.print("Enter array size: ");
    int size = scanner.nextInt();
    if (size < 2) throw new IllegalArgumentException("Array must have atleast 2 elements");

    int[] arr = new int[size];

    System.out.print("Enter array elements: ");
    for (int i = 0; i < size; i++)
      arr[i] = scanner.nextInt();

    Arrays.sort(arr);
    System.out.println("Second largest element is " + arr[arr.length - 2]);
  }
}
