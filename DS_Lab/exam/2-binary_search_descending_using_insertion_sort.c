#include <stdio.h>

void insertionSort(int *arr, int size) {
  for (int i = 1; i < size; i++) {
    int key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] <= key) {
      arr[j + 1] = arr[j];
      j--;
    }

    arr[j + 1] = key;
  }
}

int binarySearch(int *arr, int size, int elem) {
  int start = 0;
  int stop = size - 1;
  int index = -1;

  while (start <= stop) {
    int mid = start + (stop - start) / 2;
    if (arr[mid] > elem) {
      start = mid + 1;
    } else if (arr[mid] < elem) {
      stop = mid - 1;
    } else {
      index = mid;
      break;
    }
  }

  return index;
}

int main() {
  int size, elem;
  printf("Enter array size: ");
  scanf("%d", &size);

  int arr[size];
  printf("Enter array elements: ");
  for (int i = 0; i < size; i++)
    scanf("%d", &arr[i]);
  
  insertionSort(arr, size);

  printf("Sorted Array: ");
  for (int i = 0; i < size; i++) 
    printf("%d ", arr[i]);

  printf("\nEnter element to search: ");
  scanf("%d", &elem);

  int index = binarySearch(arr, size, elem);

  if (index == -1) printf("\nElement not found\n");
  else printf("\nElement found at position %d\n", (index + 1));
}
