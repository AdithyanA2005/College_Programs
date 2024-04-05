#include <stdio.h>
int main() {
  int num, temp_num, rev_num = 0, digit;
  printf("Enter a number: ");
  scanf("%d", &num);
  temp_num = num;
  
  while (temp_num > 0) {
    digit = temp_num % 10;
    rev_num = (rev_num * 10) + digit;
    temp_num = temp_num / 10;
  }

  if (rev_num == num) printf("The given number is a palindrome");
  else printf("The given number is not a palindrome");
}
