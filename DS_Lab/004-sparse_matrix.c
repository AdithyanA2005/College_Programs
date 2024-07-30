#include <stdio.h>

int main() {
  int rows, cols, noOfZeros = 0, noOfNonZeros = 0;

  printf("Enter no of rows and cols: ");
  scanf("%d%d", &rows, &cols);
  int A[rows][cols];

  // Read the matrix from the user
  printf("Enter elements:\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      scanf("%d", &A[i][j]);
    }
  }

  // Find the no of zeros and non zeros
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (A[i][j] != 0) noOfNonZeros++;
      else noOfZeros++;
    }
  }

  if (noOfNonZeros > noOfZeros) {
    printf("The Matrix is not a Sparse Matrix");
  } else {
    int k = 0;
    int S[noOfNonZeros + 1][3];
    
    // Make the first row of sparse contain (rows, cols and no of non zero elements)
    S[k][0] = rows;
    S[k][1] = cols;
    S[k][2] = noOfNonZeros;
    k++;
  
    // Make the rest of row contain details of non zero elements(their row, col, and value) 
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (A[i][j] != 0) {
          S[k][0] = i;
          S[k][1] = j;
          S[k][2] = A[i][j];
          k++;
        }
      }
    }

    // Displaying the Sparse matrix
    printf("\nThe result is:\n");
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < 3; j++) {
        printf("%d ", S[i][j]);
      }
      printf("\n");
    } 
  }
}
