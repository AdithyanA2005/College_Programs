#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main() {
  int num1, num2;
  printf("Enter 2 numbers: ");
  scanf("%d%d", &num1, &num2);

  printf("\nThe numbers before swapping are %d & %d", num1, num2);
  swap(&num1, &num2);
  printf("\nThe numbers after swapping are %d & %d", num1, num2);
}
