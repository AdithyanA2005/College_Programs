#include <stdio.h>

void swap(int *arr, int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

int partition(int *arr, int low, int high) {
  int pivot = arr[low];
  int i = low;
  int j = high;

  while (i < j) {
    while (i < high && arr[i] <= pivot) i++;
    while (j > low && arr[j] > pivot) j--;
    if (i < j) swap(arr, i, j);
  }

  swap(arr, low, j);
  return j;
}

void quickSort(int *arr, int low, int high) {
  if (low >= high) return;
  int pivot = partition(arr, low, high);
  quickSort(arr, low, pivot - 1);
  quickSort(arr, pivot + 1, high);
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

  quickSort(arr, 0, size - 1);

  printf("The sorted array: ");
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);

  int index = binarySearch(arr, size, elem);

  if (index == -1) printf("\nElement not found\n");
  else printf("\nElement fount at position %d\n", (index + 1));
}
