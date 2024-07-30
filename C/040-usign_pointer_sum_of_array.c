#include<stdio.h>

int main() {
  int size, *pt, sum = 0;
  printf("Enter the array size: ");
  scanf("%d", &size);
  
  int arr[size];

  pt = &arr[0];
  printf("\nEnter %d values: ", size);
  for (int i = 0; i < size; i++) {
    scanf("%d", pt+i);
  }

  pt = &arr[0];
  for (int i = 0; i < size; i++) {
    sum += *(pt+i);
  }

  printf("\nThe sum = %d", sum);
}
