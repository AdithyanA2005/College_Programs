#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

// Stack
char stack[MAX_SIZE];
int top = -1;
 
// String to store expressions
char postfix[20];
char infix[20];

void push(char c) {
  if (top == MAX_SIZE - 1) printf("Stack Overflow\n");
  else stack[++top] = c;
}

char pop() {
  if (top == -1) {
    printf("Stack Underflow\n");
    return '\0'; // return U to denote underflow situation
  } 
  return stack[top--]; // return value of stack[top] & top--
}

int precedenceOf(char c) {
  if (c == '^') return 3;
  else if (c == '*' || c == '/') return 2;
  else if (c == '+' || c == '-') return 1;
  else return 0;
}

int main() {
  int i, p = 0;
  printf("INFIX TO POSTFIX\n----- -- -------\n");
  printf("Enter infix expression: ");
  scanf("%s", infix);

  for (int i = 0; i < strlen(infix); i++) {
    switch (infix[i]) {
      case '(':
        push('('); // Adding parentheses to the stack
        break;
      case ')':
        while (stack[top] != '(') 
          postfix[p++] = pop(); // Adding all elements to postfix till '(' is encountered
        pop(); // Remove the '(' from the stack
        break;
      case '+':
      case '-':
      case '*':
      case '/':
      case '^':
        while (precedenceOf(infix[i]) <= precedenceOf(stack[top]) && stack[top] != '(') {
          postfix[p++] = pop();
        }
        push(infix[i]);
        break;
      default:
        postfix[p++] = infix[i];
    }
  }

  while (top != -1) postfix[p++] = pop(); // Add all the remaining to postfix
  postfix[p] = '\0'; // Add null terminator to postfix string
  printf("The Postfix Expression: %s", postfix);
}
