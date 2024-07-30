import java.util.Scanner;

class MatrixTranspose {
  public static void printMatrix(int[][] matrix) {
    for (int i = 0; i < matrix.length; i++) {
      for (int j = 0; j < matrix[0].length; j++) {
        System.out.print(matrix[i][j] + " ");
      }
      System.out.println();
    }
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    System.out.print("Enter no of rows: ");
    int rows = scanner.nextInt();

    System.out.print("Enter no of cols: ");
    int cols = scanner.nextInt();

    if (rows <= 0 || cols <= 0) {
      throw new IllegalArgumentException("Invalid matrix dimensions");
    }

    int[][] matrix = new int[rows][cols];
    System.out.println("Enter matrix elements:");
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        matrix[i][j] = scanner.nextInt();
      }
    }

    System.out.println("\nThe original matrix:");
    printMatrix(matrix);

    int[][] transpose = new int[rows][cols];
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        transpose[j][i] = matrix[i][j];
      }
    }

    System.out.println("\nThe tranpose of matrix:");
    printMatrix(transpose);
  }
}
