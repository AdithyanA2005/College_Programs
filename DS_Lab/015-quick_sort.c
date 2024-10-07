#include <stdio.h>

void swap(int arr[], int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

int partition(int arr[], int low, int high) {
  int pivot = arr[low];
  int i = low;
  int j = high;

  while (i < j) {
    while (i < high && arr[i] <= pivot) i++;
    while (j > low && arr[i] > pivot) j--;
    if (i < j) swap(arr, i, j);
  }

  swap(arr, low, j);
  return j;
}

void quick_sort(int arr[], int low, int high) {
  if (low >= high) return;
  int pivot = partition(arr, low, high);
  quick_sort(arr, pivot + 1, high);
  quick_sort(arr, low, pivot - 1);
}

int main() {
  int size;
  printf("Enter array size: ");
  scanf("%d", &size);

  int arr[size];
  printf("Enter array elements: ");
  for (int i = 0; i < size; i++) scanf("%d", &arr[i]);

  quick_sort(arr, 0, size - 1);

  printf("Sorted array is: ");
  for (int i = 0; i < size; i++) printf("%d ", arr[i]);
}
