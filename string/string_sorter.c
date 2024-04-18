#include <stdio.h>
#include <string.h>

int main() {
  int size;
  char string[100];
  gets(string);
  size = strlen(string);
  
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i -1; j++) {
      if (string[j] > string[j+1]) {
        int temp = string[j];
        string[j] = string[j+1];
        string[j+1] = temp;
      }
    }
  }

  puts(string);
}
