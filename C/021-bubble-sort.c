#include <stdio.h>
int main() {
  int size, temp;
  printf("Enter the size of the array: ");
  scanf("%d", &size);

  // Create the array
  int arr[size];
  printf("\nENTER THE VALUES OF THE ARRAY\n");
  for (int i=0; i<size; i++) {
    printf("Enter element %d: ", i+1);
    scanf("%d", &arr[i]);
  }

  // Bubble Sort
  for (int i=0; i<size-1; i++) {
    for (int j=0; j<size-1-i; j++){
      if (arr[j] > arr[j+1]) {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }

  // Display the sorted array
  printf("\nTHE ARRAY ELEMENTS ARE:\n");
  for (int i=0; i<size; i++) {
    printf("%d ", arr[i]);
  }

  
  return 0;
}
