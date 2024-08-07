#include <stdio.h>

int main() {
  int size, temp;
  printf("Enter array size: ");
  scanf("%d", &size);
  int arr[size];

  printf("Enter array elements: ");
  for (int i = 0; i < size; i++)
    scanf("%d", &arr[i]);

  for (int i = 0; i < size - 1; i++)
    for (int j = i + 1; j < size; j++)
      if (arr[i] > arr[j]) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }

  printf("Sorted array is: ");
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);
}
