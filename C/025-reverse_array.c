#include <stdio.h>
int main() {
  int i, size, temp;
  printf("Enter the size of the array: ");
  scanf("%d", &size);

  // Create the array
  int arr[size];
  for (i = 0; i < size; i++) {
    printf("Enter element %d: ", i+1);
    scanf("%d", &arr[i]);
  }

  // Reverse the array
  for (i = 0; i < size / 2; i++) {
    temp = arr[i];
    arr[i] = arr[size - i - 1];
    arr[size - i - 1] = temp;
  }

  // Print the reverserd array
  printf("\nThe reversed array is: ");
  for (i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
}
