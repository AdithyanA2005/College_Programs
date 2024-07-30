#include <stdio.h>

int main() {
  int i, size, target, mid, index = -1;
  printf("Enter the size of the array: ");
  scanf("%d", &size);

  int start = 0, end = size - 1;

  // Create the array
  int arr[size];
  for (i = 0; i < size; i++) {
    printf("Enter element %d: ", i + 1);
    scanf("%d", &arr[i]);
  }

  // Enter element to search
  printf("Enter element to search: ");
  scanf("%d", &target);

  while (start <= end) {
    mid = (end + start) / 2;

    if (arr[mid] == target) {
      index = mid;
      break;
    } else if (arr[mid] < target) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }

  if (index == -1) {
    printf("Element not found");
  } else {
    printf("Element found at position %d", index + 1);
  }

  return 0;
}
