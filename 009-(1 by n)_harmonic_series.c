#include <stdio.h>

int main() {
  int n, i;
  float sum = 0;
  printf("Enter value of n: ");
  scanf("%d", &n);

  for (i = 1; i <= n; i++) {
    printf("1/%d + ", i);
    sum += (1.0/i);
  }

  printf("\b\b= %f", sum);
}
