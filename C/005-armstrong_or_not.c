#include <stdio.h>
#include <math.h>

int main() {
  int num, temp, digit, n = 0, result = 0;
  printf("Enter the number: ");
  scanf("%d", &num);

  // Calculate the no of digits in the entered number
  for (temp = num; temp > 0; temp /= 10)
    n = n + 1;

  // Calculate armstrong and store it in result
  for (temp = num; temp > 0; temp /= 10) {
    digit = temp % 10;
    result += pow(digit, n);
  }

  // Check if it a armstrong number
  if (num == result) printf("It's a armstrong number");
  else printf("It's not a armstrong number");
}
