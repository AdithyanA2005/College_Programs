import java.util.Scanner;
import java.util.Arrays;

class BinarySearch {
    private static int binarySearch(int[] arr, int target) {
        int start = 0;
        int stop = arr.length - 1;

        while (start <= stop) {
            int mid = (start + stop) / 2;

            if (arr[mid] > target)
                stop = mid - 1;
            else if (arr[mid] < target)
                start = mid + 1;
            else
                return mid;
        }

        return -1;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter array size: ");
        int size = scanner.nextInt();

        int[] arr = new int[size];
        System.out.print("Enter array elements: ");
        for (int i = 0; i < size; i++)
            arr[i] = scanner.nextInt();
        Arrays.sort(arr);

        System.out.print("Enter element to search: ");
        int target = scanner.nextInt();

        int index = binarySearch(arr, target);
        if (index == -1)
            System.out.println("Element not found");
        else
            System.out.println("Element found at position " + (index + 1));

        scanner.close();
    }
}