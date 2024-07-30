#include <stdio.h>

void displayRowSums(int matrix[][100], int rows, int cols) {
    int i, j, rowSum;

    printf("Row sums:\n");
    for (i = 0; i < rows; i++) {
        rowSum = 0;
        for (j = 0; j < cols; j++) {
            rowSum += matrix[i][j];
        }
        printf("Row %d sum: %d\n", i + 1, rowSum);
    }
}

int main() {
    int rows, cols;

    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    int matrix[100][100];

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    displayRowSums(matrix, rows, cols);

    return 0;
}
