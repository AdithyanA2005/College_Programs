#include <stdio.h>
int main() {
  char operator;
  double num1, num2, result;

  printf("Enter a operation (+, -, *, /): ");
  scanf("%c", &operator);

  printf("Enter 2 numbers: ");
  scanf("%lf%lf", &num1, &num2);


  switch (operator) {
    case '+':
      result = num1 + num2;
      break;
    case '-':
      result = num1 - num2;
      break;
    case '*':
      result = num1 * num2;
      break;
    case '/':
      if (num2 == 0) {
        printf("Error! Division by zero");
        break;
      }
      result = num1 / num2;
      break;
  }

  printf("\n%lf %c %lf = %lf", num1, operator, num2, result);
}
