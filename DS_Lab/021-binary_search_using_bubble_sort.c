#include <stdio.h>

void bubbleSort(int * arr, int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j+1]) { // For Descending use "arr[j] < arr[j+1]"
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}

int binarySearch(int *arr, int size, int elem) {
  int low = 0;
  int high = size - 1;

  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] > elem) high = mid - 1;
    else if (arr[mid] < elem) low = mid + 1;
    else return mid;
  }

  return -1;
}

int main() {
  int size, elem;
  printf("Enter array size: ");
  scanf("%d", &size);

  int arr[size];
  printf("Enter array elements: ");
  for (int i = 0; i < size; i++)
    scanf("%d", &arr[i]);

  printf("Enter element to search: ");
  scanf("%d", &elem);

  bubbleSort(arr, size);

  printf("The sorted array: ");
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);

  int index = binarySearch(arr, size, elem);

  if (index == -1) printf("\nElement not found\n");
  else printf("\nElement fount at position %d\n", (index + 1));
}
