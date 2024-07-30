#include <stdio.h>

int main() {
  int size, elem, pos;
  printf("Enter the size of the array: ");
  scanf("%d", &size);

  int oriArr[size], arr[size+1];

  printf("\nEnter elements of the array\n");
  for (int i = 0; i < size; i++) {
    printf("Enter element %d: ", i + 1);
    scanf("%d", &oriArr[i]);
  }

  printf("\nEnter value of new element: ");
  scanf("%d", &elem);

  printf("Enter position of new element (1, %d): ", size);
  scanf("%d", &pos);

  for (int i = 0; i < size + 1; i++) {
    if (i < (pos - 1)) 
      arr[i] = oriArr[i];
    else if (i == (pos - 1))
      arr[i] = elem;
    else 
      arr[i] = oriArr[i-1];
  }

  printf("\nARR\n");
  for (int i=0; i < size + 1; i++) {
    printf("%d ", arr[i]);
  }
}

