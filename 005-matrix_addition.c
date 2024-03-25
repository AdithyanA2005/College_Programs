#include <stdio.h>
int main() {
  int m, n;
  printf("Enter no of rows and columns: ");
  scanf("%d%d", &m, &n);

  int a[m][n], b[m][n], c[m][n];

  // Add values to matrix A
  printf("ENTER VALUES OF MATRIX A\n");
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
    }
    printf("\n");
  }
  
  // Add values of matrix B
  printf("\nENTER VALUES OF MATRIX B\n");
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &b[i][j]);
    }
    printf("\n");
  }

  // Set C = A + B
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      c[i][j] = a[i][j] + b[i][j];
    }
  }
  
  // Display C
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", c[i][j]);
    }
    printf("\n");
  } 

  return 0;
}
