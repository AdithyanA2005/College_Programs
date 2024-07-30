#include <stdio.h>
int main() {
  int size;
  printf("Enter the size of the array: ");
  scanf("%d", &size);

  // Initialize and get array values
  int arr[size];
  for (int i = 0; i < size; i++) {
    printf("Enter element %d: ", i + 1);
    scanf("%d", & arr[i]);
  }

  // Find the largest element
  int largest = arr[0];
  for (int i = 0; i < size; i++) {
    if (arr[i] > largest) largest = arr[i];
  }

  // Display the largest element
  printf("The largest element in the array is %d", largest);
}
