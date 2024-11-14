#include <stdio.h>

int main() {
  int n, m, k = 0, noOfZeros = 0, noOfNonZeros = 0;
  printf("Enter no of rows: ");
  scanf("%d", &n);
  printf("Enter no of cols: ");
  scanf("%d", &m);

  int matrix[n][m];
  int trans[m][n];

  // Read matrix elements
  printf("Enter matrix elements:\n");
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      scanf("%d", &matrix[i][j]);

  // Find transpose of matrix
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      trans[i][j] = matrix[j][i];

  // Display transpose of matrix
  printf("The transpose matrix:\n");
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", trans[i][j]);
    }
    printf("\n");
  }

  // Count no of zeros and non zeros
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (trans[i][j] == 0) noOfZeros++;
      else noOfNonZeros++;

  // Check if its a sparse matrix
  if (noOfNonZeros > noOfZeros) {
    printf("It is not a sparse matrix");
  } else {
    // Find the sparse tuple
    int sparse[noOfNonZeros + 1][3];
    sparse[k][0] = m;
    sparse[k][1] = n;
    sparse[k][2] = noOfNonZeros;
    k++;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (trans[i][j]) {
          sparse[k][0] = i;
          sparse[k][1] = j;
          sparse[k][2] = trans[i][j];
          k++;
        }

    // Display the sparse tuple
    printf("\nThe sparse tuple is: \n");
    for (int i = 0; i < noOfNonZeros + 1; i++) {
      for (int j = 0; j < 3; j++) {
        printf("%d ", sparse[i][j]); 
      }
      printf("\n");
    } 
  }
}
