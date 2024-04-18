#include <stdio.h>
int main() {
  int num, temp-num, rev-num = 0, digit;
  printf("Enter a number: ");
  scanf("%d", &num);
  temp-num = num;
  
  while (temp-num > 0) {
    digit = temp-num % 10;
    rev-num = (rev-num * 10) + digit;
    temp-num = temp-num / 10;
  }

  if (rev-num == num) printf("The given number is a palindrome");
  else printf("The given number is not a palindrome");
}
