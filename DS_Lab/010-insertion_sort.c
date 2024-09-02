#include <stdio.h>

int main() {
  int size, temp;
  printf("Enter array size: ");
  scanf("%d", &size);
  int arr[size];

  printf("Enter array elements: ");
  for (int i = 0; i < size; i++)
    scanf("%d", &arr[i]);

  for (int i = 1; i < size; i++) {
    int j = i - 1;
    int current = arr[i];

    while (j >= 0 && arr[j] > current) {
      arr[j + 1] = arr[j];
      j--;
    }

    arr[j + 1] = current;
  }

  printf("Sorted array is: ");
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);
}
