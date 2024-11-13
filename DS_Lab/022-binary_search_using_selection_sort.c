#include <stdio.h>

void selectionSort(int * arr, int size) {
  for (int i = 0; i < size - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < size; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }

    int temp = arr[i];
    arr[i] = arr[minIndex];
    arr[minIndex] = temp;
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

  selectionSort(arr, size);

  printf("The sorted array: ");
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);

  int index = binarySearch(arr, size, elem);

  if (index == -1) printf("\nElement not found\n");
  else printf("\nElement fount at position %d\n", (index + 1));
}
