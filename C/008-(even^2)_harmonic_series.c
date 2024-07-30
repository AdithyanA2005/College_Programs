#include <stdio.h>

int main() {
  int i, sum = 0, n;
  printf("Enter value of n: ");
  scanf("%d", &n);

  for (int i = 2; i <= n; i+= 2) {
    printf("%d^2 ", i);
    sum += i * i;
  }

  printf("= %d", sum);
}
