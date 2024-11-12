#include <stdio.h>

void merge(int *arr, int low, int mid, int high) {
  int i = low;
  int j = mid + 1;
  
  int k = 0;
  int newArr[high - low + 1];

  while (i <= mid && j <= high) {
    if (arr[i] <= arr[j]) newArr[k++] = arr[i++];
    else newArr[k++] = arr[j++];
  }

  while (i <= mid) newArr[k++] = arr[i++];
  while (j <= high) newArr[k++] = arr[j++];

  for (int i = 0; i < k; i++)
    arr[low + i] = newArr[i];
}

void mergeSort(int *arr, int low, int high) {
  if (low >= high) return;
  int mid = low + (high - low) / 2;
  mergeSort(arr, low, mid);
  mergeSort(arr, mid + 1, high);
  merge(arr, low, mid, high);
}

int binarySearch(int *arr, int size, int elem) {
  int start = 0;
  int stop = size - 1;
  int index = -1;

  while (start <= stop) {
    int mid = start + (stop - start) / 2;
    if (arr[mid] > elem) {
      stop = mid - 1;
    } else if (arr[mid] < elem) {
      start = mid + 1;
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
  
  printf("Enter element to search: ");
  scanf("%d", &elem);

  mergeSort(arr, 0, size - 1);

  printf("Sorted Array: ");
  for (int i = 0; i < size; i++) 
    printf("%d ", arr[i]);

  int index = binarySearch(arr, size, elem);

  if (index == -1) printf("\n\nElement not found\n");
  else printf("\n\nElement found at position %d\n", (index + 1));
}
