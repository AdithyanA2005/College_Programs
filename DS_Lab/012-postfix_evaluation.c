#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Stack
int stack[MAX_SIZE];
int top = -1;

// Stack Operations
void push(int item) {
  if (top == MAX_SIZE - 1) printf("Stack Overflow\n");
  else stack[++top] = item;
}

int pop() {
  if (top == -1) {
    printf("Stack Underflow\n");
    return -1;
  }
  return stack[top--];
}

int main() {
  char postfix[20];

  printf("POSTFIX EVALUATION\n------- ----------\n");
  printf("Enter postfix expression: ");
  scanf("%s", postfix);

  for (int i = 0; i < strlen(postfix); i++) {
    if (isalnum(postfix[i])) {
      push(postfix[i] - '0');
    } else {
      char opr = postfix[i];
      int num1 = pop();
      int num2 = pop();

      if (opr == '+') push(num1 + num2);
      else if (opr == '-') push(num1 - num2);
      else if (opr == '*') push(num1 * num2);
      else if (opr == '/') push(num1 / num2);
      else if (opr == '^') push(pow(num1, num2));
      else {
        printf("Unknown Operator");
        exit(0);
      }
    }
  } 

  printf("Evaluated value: %d", pop());
}
