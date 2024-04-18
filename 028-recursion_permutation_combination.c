// Combination Formula
// nCr = n! / [r! - (n-r)!]

// Permutation Formula
// nPr = n! / (n-r)!

#include <stdio.h>
int factorial(int);

int factorial(int n) {
  if (n == 1) return 1;
  return n * factorial(n - 1);
}

int main() {
  int n, r;
  float C, P;
  
  printf("Enter values or n & r: ");
  scanf("%d%d", &n, &r);

  // Check if r is valid
  if (r < 0 || r > n) {
    printf("Error! Invalid value for r");
    return 1;
  }

  P = (float)factorial(n) / factorial(n - r);
  C = (float)factorial(n) / (factorial(r) * factorial(n - r));

  printf("\nnCr = %f", C);
  printf("\nnPr = %f", P);

  return 0;
}
