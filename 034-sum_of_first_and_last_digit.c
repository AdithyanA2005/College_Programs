#include <stdio.h>

int main() { 
  int num, sum, firstDigit = 0, lastDigit = 0;
  printf("Enter a number: ");
  scanf("%d", &num);

  lastDigit = num % 10;
  for(firstDigit = num; firstDigit >= 10; firstDigit /= 10);

  sum = firstDigit + lastDigit;
  printf("The sum is: %d", sum);

  return 0;
}
