#include <stdio.h>

int main() {
  int n, m;
  printf("Enter no of rows: ");
  scanf("%d", &n);
  printf("Enter no of cols: ");
  scanf("%d", &m);

  int A[n][m];
  int B[n][m];
  int C[n][m];

  // Read matrix 1
  printf("\nEnter elements of matrix 1:\n");
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      scanf("%d", &A[i][j]);
  
  // Read matrix 2
  printf("\nEnter elements of matrix 2:\n");
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      scanf("%d", &B[i][j]);

  // Calculate the sum matrix
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      C[i][j] = A[i][j] + B[i][j];
    
  // Display the sum matrix
  printf("\nThe sum is:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
       printf("%d ", C[i][j]);
    }
    printf("\n");
  }

  // Calculate noOfZeros and noOfNonZeros
  int noOfZeros = 0, noOfNonZeros = 0;
  for (int i = 0; i < n; i++) 
    for (int j = 0; j < m; j++) 
      if (C[i][j] == 0) noOfZeros++;
      else noOfNonZeros++;


  // Check if its a sparse matrix
  if (noOfNonZeros > noOfZeros) {
    printf("It is not a sparse matrix");
  } else {
    // Find the sparse tuple
    int k = 0;
    int sparse[noOfNonZeros + 1][3];
    sparse[k][0] = n;
    sparse[k][1] = m;
    sparse[k][2] = noOfNonZeros;
    k++;

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (C[i][j]) {
          sparse[k][0] = i;
          sparse[k][1] = j;
          sparse[k][2] = C[i][j];
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
