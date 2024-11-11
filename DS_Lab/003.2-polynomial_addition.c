#include <stdio.h>

#define MAX 100

void printPoly(int *p, int n) {
  int started = 0;
  for (int i = n; i >= 0; i--) {
    if (p[i]) {
      if (started) printf(" + ");
      if (i == 0) printf("%d", p[i]);
      else printf("%dX^%d", p[i], i);
      started = 1;
    }
  }
}

void addPoly(int * p1, int n1, int * p2, int n2, int * sum) {
  int i = 0, j = 0, k = 0;
  while (i <= n1 && j <= n2) sum[k++] = p1[i++] + p2[j++];
  while (i <= n1) sum[k++] = p1[i++];
  while (j <= n2) sum[k++] = p2[j++];
}

int main() {
  int n1, n2, p1[MAX], p2[MAX], sum[MAX];
  printf("Enter first polynomial degree: ");
  scanf("%d", &n1);
  printf("Enter first polynomial coefficients: ");
  for (int i = n1; i >= 0; i--) scanf("%d", &p1[i]);
  
  printf("Enter second polynomial degree: ");
  scanf("%d", &n2);
  printf("Enter second polynomial coefficients: ");
  for (int i = n2; i >= 0; i--) scanf("%d", &p2[i]);

  printf("\nThe first polynomial: ");
  printPoly(p1, n1);

  printf("\nThe second polynomial: ");
  printPoly(p2, n2);

  addPoly(p1, n1, p2, n2, sum);

  printf("\nThe sum: ");
  printPoly(sum, n1 > n2 ? n1 : n2);
  printf("\n");
}
