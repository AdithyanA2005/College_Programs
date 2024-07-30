import java.util.Scanner;

class SecondLargestElement2 {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    System.out.print("Enter array size: ");
    int size = scanner.nextInt();
    if (size < 2) throw new IllegalArgumentException("Array should have atleast 2 elements");

    int[] arr = new int[size];

    System.out.print("Enter array elements: ");
    for (int i = 0; i < size; i++) 
      arr[i] = scanner.nextInt();

    int largest = arr[0];
    int secondLargest = arr[0];

    for (int i = 0; i < arr.length; i++) {
      if (arr[i] > largest) {
        secondLargest = largest;
        largest = arr[i];
      } else if (arr[i] > secondLargest && arr[i] < largest) {
        secondLargest = arr[i];
      }
    }

    System.out.println("Second largest element is " + secondLargest);
  }
}
