#include <stdio.h>

// Function to concatenate two strings
void concat(char str1[], char str2[]) {
  int i, j;

  // Find the length of str1
  for (i = 0; str1[i] != '\0'; i++);

  // Concatenate str2 to str1
  for (j = 0; str2[j] != '\0'; j++) {
    str1[i + j] = str2[j];
  }

  // Add null terminator to mark the end of the concatenated string
  str1[i + j] = '\0';
}

int main() {
  char str1[100], str2[100];

  printf("Enter the first string: ");
  scanf("%s", str1);

  printf("Enter the second string: ");
  scanf("%s", str2);

  concat(str1, str2);

  printf("Concatenated string: %s\n", str1);
}
