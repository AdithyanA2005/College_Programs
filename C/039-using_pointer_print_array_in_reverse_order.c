#include <stdio.h>

int main() {
  int limit, i, arr[15];
  int *pt;

  printf("Enter no of elements: ");
  scanf("%d", &limit);

  pt = &arr[0];
  printf("Enter %d elements: ", limit);
  for (i = 0; i < limit; i++) {
    scanf("%d", pt);
    pt++;
  }

  pt = &arr[limit - 1];
  printf("\n The elements of array in reverse order are: ");
  for (i = 0; i < limit; i++) {
    printf("%d ", *pt);
    pt--;
  }
}
