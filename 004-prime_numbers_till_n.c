#include <stdio.h>

int main() {
  int num, isPrime;

  printf("Enter number: ");
  scanf("%d", &num);

  for (int i = 2; i <= num; i++) {
    isPrime = 1;

    for (int j = 2; j < i; j++) {
      if (i % j == 0) isPrime = 0;
    }

    if (isPrime == 1)
      printf("%d ", i);
  }
}
