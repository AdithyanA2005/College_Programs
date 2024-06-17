#include <stdio.h>

int main() {
  int length, isPalindrome = 1;
  char str[100], rev_str[100];
  printf("Enter string: ");
  scanf("%s", str);

  // Find the length of the string
  for (length = 0; str[length] != '\0'; length++);
  printf("%d", length);

  // Check if its palindrome
  for (int i = 0; i < length / 2; i++) {
    if (str[i] != str[length - i -1]) {
      isPalindrome = 0;
      break;
    }
  }

  // Print the result
  if (isPalindrome)
    printf("The string is a palindrome");
  else
    printf("The string is not a palindrome");
}
