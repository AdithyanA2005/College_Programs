#include <stdio.h>

int main() {
  char ch;
  printf("Enter a character: ");
  scanf("%c", &ch);

  if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) 
    printf("It's an alphabet");
  else 
    printf("It's not an alphabet");
}
