#include <stdio.h>
int main() {
  int a_rows, a_cols, b_rows, b_cols;
  printf("Enter no of rows and cols of matrix A: ");
  scanf("%d%d", &a_rows, &a_cols);

  b_rows = a_cols;
  printf("Enter no of cols of matrix B: ");
  scanf("%d", &b_cols);

  printf("The order of matrix C will be %d x %d\n", a_rows, b_cols);

  
  int a[a_rows][a_cols], b[b_rows][b_cols], c[a_rows][b_cols];

  // Get values of matrix A
  printf("\nENTER VALUES OF MATRIX A:\n");
  for (int i = 0; i < a_rows; i++) {
    for (int j = 0; j < a_cols; j++) {
      scanf("%d", &a[i][j]);
    }
  }

  // Get values of matrix B
  printf("\nENTER VALUES OF MATRIX B:\n");
  for (int i = 0; i < b_rows; i++) {
    for (int j = 0; j < b_cols; j++) {
      scanf("%d", &b[i][j]);
    }
  }

  // Set C = A * B
  // first cols = second rows
  // resut first rows  & second cols
  for (int i = 0; i < a_rows ; i++) {
    for (int j = 0; j < b_cols; j++) {
      c[i][j] = 0;

      for (int k = 0; k < b_rows; k++) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  printf("\nVALUES OF MATRIX C ARE:\n");
  for (int i = 0; i < a_rows; i++) {
    for (int j = 0; j < b_cols; j++) {
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }

  return 0;
}
