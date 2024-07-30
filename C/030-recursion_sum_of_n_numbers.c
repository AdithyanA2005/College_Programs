#include <stdio.h>

int sum(int);

int main() {
  int n;
  printf("Enter the limit: ");
  scanf("%d", &n);
  printf("Sum of numbers 1 to %d is %d", n, sum(n));
}

int sum(int n) {
  if (n == 0) return 0;
  return n + sum(n-1);
}
