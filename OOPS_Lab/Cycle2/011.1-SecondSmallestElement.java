import java.util.Scanner;

class SecondSmallestElement1 {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    System.out.print("Enter array size: ");
    int size = scanner.nextInt();
    int[] arr = new int[size];

    System.out.print("Enter array elements: ");
    for (int i = 0; i < size; i++) {
      arr[i] = scanner.nextInt(); 
    }

    int smallest = Integer.MAX_VALUE;
    int secondSmallest = Integer.MAX_VALUE;

    for (int i = 0; i < size; i++) {
      if (arr[i] < smallest) {
        secondSmallest = smallest;
        smallest = arr[i]; 
      } else if (arr[i] < secondSmallest && arr[i] > smallest) {
        secondSmallest = arr[i];
      }
    } 

    System.out.print("The second smallest element is " + secondSmallest);
  }
}
