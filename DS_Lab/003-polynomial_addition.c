#include <stdio.h>

#define MAX_DEGREE 100

void printPoly(int *p, int n) {
  for (int i = n; i >= 0; i--) {
    if (p[i]) {
      // From second term onwards add a "+" symbol
      if (i != n)
        printf(" + ");

      if (i == 0)
        printf("%d", p[i]);
      else
        printf("%dx^%d", p[i], i);
    }
  }
}

void addPoly(int *p1, int n1, int *p2, int n2, int *sum) {
  int i = 0, j = 0, k = 0;

  while (i <= n1 || j <= n2) {
    int c1 = (i <= n1) ? p1[i++] : 0;
    int c2 = (j <= n2) ? p2[j++] : 0;
    sum[k++] = c1 + c2;
  }
}

int main() {
  int n1, n2;
  int p1[MAX_DEGREE], p2[MAX_DEGREE], sum[MAX_DEGREE];

  printf("CREATE POLYNOMIAL 1\n");
  printf("Enter degree: ");
  scanf("%d", &n1);

  printf("Enter coefficient: ");
  for (int i = n1; i >= 0; i--)
    scanf("%d", &p1[i]);

  printf("\nCREATE POLYNOMIAL 2\n");
  printf("Enter degree: ");
  scanf("%d", &n2);

  printf("Enter coefficient: ");
  for (int i = n2; i >= 0; i--)
    scanf("%d", &p2[i]);

  printf("\nFirst polynomial: ");
  printPoly(p1, n1);

  printf("\nSecond polynomial: ");
  printPoly(p2, n2);

  addPoly(p1, n1, p2, n2, sum);
  printf("\nSum of Polynomials: ");
  printPoly(sum, n1 > n2 ? n1 : n2);

  return 0;
}
