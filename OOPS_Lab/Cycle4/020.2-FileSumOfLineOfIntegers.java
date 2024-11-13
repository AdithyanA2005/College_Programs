import java.io.*;

class FileSumOfLineOfIntegers {
  public static void main(String[] args) {
    int sum = 0;

    try (BufferedReader reader = new BufferedReader(new FileReader("020-file.txt"))) {
      String line = reader.readLine();
      String[] numbers = line.split("\\s+");

      for (String number : numbers) {
        int num = Integer.parseInt(number);
        sum += num;
      }

      System.out.println("The Sum is " + sum);
    } catch (IOException e) {
      System.err.println("Error reading file: " + e.getMessage());
    } catch (NumberFormatException e) {
      System.err.println("Error parsing integer: " + e.getMessage());
    }
  }
}
