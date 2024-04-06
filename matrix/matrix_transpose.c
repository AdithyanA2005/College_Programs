#include <stdio.h> 
int main() {
  int rows, cols;
  printf("Enter no of rows & cols: ");
  scanf("%d%d", &rows, &cols);
  
  int A[rows][cols], B[cols][rows];

  // Take a matrix as input from user
  printf("\nEnter elements of the matrix:\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      scanf("%d", &A[i][j]); 
    }
  }

  // Find the transpose of the matrix
  for (int i = 0; i < cols; i++) {
    for (int j = 0; j < rows; j++) {
      B[i][j] = A[j][i];
    }
  }

  // Print transpose of the matrix
  printf("\nThe transpose of the matrix is:\n");
  for (int i = 0; i < cols; i++) {
    for (int j = 0; j < rows; j++) {
      printf("%d ", B[i][j]);
    }
    printf("\n");
  }
}
