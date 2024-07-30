import java.util.Scanner;

class MatrixMultiplication {
  public static int[][] getMatrix(int rows, int cols) {
    Scanner scanner = new Scanner(System.in);
    int[][] matrix = new int[rows][cols];

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        matrix[i][j] = scanner.nextInt();
      }
    }

    return matrix;
  }

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

    System.out.print("Enter no of rows and cols of matrix A: ");
    int a_rows = scanner.nextInt();
    int a_cols = scanner.nextInt();

    int b_rows = a_cols;
    System.out.print("Enter no of cols of matrix B: ");
    int b_cols = scanner.nextInt();

    System.out.println("Enter elements of matrix A:");
    int[][] A = getMatrix(a_rows, a_cols);

    System.out.println("Enter elements of matrix B:");
    int[][] B = getMatrix(b_rows, b_cols);

    int[][] C = new int[a_rows][b_cols];
    for (int i = 0; i < a_rows; i++) {
      for (int j = 0; j < b_cols; j++) {
        for (int k = 0; k < a_cols; k++) {
          C[i][j] += A[i][k] * B[k][j];
        }
      }
    } 

    System.out.println("\nMatrix A:");
    printMatrix(A);

    System.out.println("\nMatrix B:");    
    printMatrix(B);
      
    System.out.println("\nProduct of matrix A & B:");    
    printMatrix(C);
  }
}
