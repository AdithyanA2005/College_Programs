#include<stdio.h>
#include<string.h>

int main() {
  int vcount = 0, ccount = 0, length;
  char str[500];

  printf("Enter string: ");
  scanf("%s", str);

  length = strlen(str);

  for (int i = 0; i < length; i++) {
    char ch = str[i];

    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') vcount++;
    else ccount++;
  }

  printf("Vowel count: %d\nConsonant count: %d", vcount, ccount);
}
