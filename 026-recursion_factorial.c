#include <stdio.h>

int factorial(int n) {
  if (n == 0) return 1;
  return n * factorial(n - 1);
}

int main() {
  int num, fact;
  printf("Enter a number: ");
  scanf("%d", &num);

  if (num < 0) {
    printf("Factorial can't be found for a negative number");
  } else {
    fact = factorial(num);
    printf("Factorial of %d is %d", num, fact);
  }
}
