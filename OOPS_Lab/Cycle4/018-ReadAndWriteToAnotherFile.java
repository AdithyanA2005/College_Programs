import java.io.*;

class ReadAndWriteToAnotherFile {
  public static void main(String[] args) {
    String inputFile = "018-input.txt";
    String outputFile = "018-output.txt";

    try (BufferedReader reader = new BufferedReader(new FileReader(inputFile));
        BufferedWriter writer = new BufferedWriter(new FileWriter(outputFile))) {

      String line;
      while ((line = reader.readLine()) != null) {
        writer.write(line);
        writer.newLine();
      }

    } catch (IOException e) {
      System.err.println("Error: " + e.getMessage());
    }
  }
}
