#include <stdio.h>

void mergesort(int arr[], int low, int high) {
  if (low >= high) return;

  int mid = low + (high - low) / 2;
  mergesort(arr, low, mid);
  mergesort(arr, mid + 1, high);

  int newArr[high - low + 1];
  int i = low;
  int j = mid + 1;
  int k = 0;

  while (i <= mid && j <= high) {
    if (arr[i] <= arr[j]) newArr[k++] = arr[i++];
    else newArr[k++] = arr[j++];
  } 

  while (i <= mid) newArr[k++] = arr[i++];

  while (j <= high) newArr[k++] = arr[j++];

  for (i = 0; i < k; i++) arr[low + i] = newArr[i];
}

int main() {
  int size;
  printf("Enter array size: ");
  scanf("%d", &size);

  int arr[size];
  printf("Enter array elements: ");
  for (int  i = 0; i < size; i++) scanf("%d", &arr[i]);

  mergesort(arr, 0, size - 1);
  
  printf("Sorted array: ");
  for (int i = 0; i < size; i++) printf("%d ", arr[i]);
}
