#include <stdio.h> 
int main() {
  int size, num, index = -1;
  printf("Enter the size of the array: ");
  scanf("%d", &size);

  // Initialize and set values to an array
  int arr[size];
  for (int i = 0; i < size; i++) {
    printf("Enter element %d: ", i);
    scanf("%d", &arr[i]);
  }

  // Get a value and search for it
  printf("\nEnter the number to search: ");
  scanf("%d", &num);
  for (int i = 0; i < size; i++) {
    if (arr[i] == num) index = i;
  }

  // Display final output
  if (index == -1) printf("Element not found in array");
  printf("Element found at index %d", index);
}
