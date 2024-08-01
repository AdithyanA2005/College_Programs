import java.io.*;

class FileWordCounter {
  public static void main(String[] args) {
    int wordCount = 0;

    try (BufferedReader reader = new BufferedReader(new FileReader("019-file.txt"))) {
      String line;
      while ((line = reader.readLine()) != null) {
        String[] words = line.split("\\s+");
        wordCount += words.length;
      }

      System.out.println("Word Count: " + wordCount);

    } catch (IOException e) {
      System.err.println("Error reading file: " + e.getMessage());
    }
  }
}
