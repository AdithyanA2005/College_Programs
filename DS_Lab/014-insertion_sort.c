#include <stdio.h>

void insertionSort(int size, int arr[]) {
  for (int i = 1; i < size; i++) {
    int key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }

    arr[j + 1] = key;
  }
}

int main() {
  int size;
  printf("Enter array size: ");
  scanf("%d", &size);

  int arr[size];
  printf("Enter array elements: ");
  for (int i = 0; i < size; i++) scanf("%d", &arr[i]);

  insertionSort(size, arr);

  printf("Sorted array is: ");
  for (int i = 0; i < size; i++) printf("%d ", arr[i]);
}
