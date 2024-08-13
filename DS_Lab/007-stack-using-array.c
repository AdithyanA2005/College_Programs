#include <stdio.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int data) {
  if (top == MAX_SIZE - 1) {
    printf("Stack Overflow\n");
    return;
  }
  stack[++top] = data;
}

int pop() {
  if (top == -1) {
    printf("Stack Underflow\n");
    return -1;
  }
  return stack[top--];
}

int peek() {
  if (top == -1) {
    printf("Stack is empty\n");
    return -1;
  }
  return stack[top];
}

int isEmpty() {
  return top == -1;
}

int isFull() {
  return top == MAX_SIZE - 1;
}

int main() {
    push(10);
    push(20);
    push(30);

    printf("The stack is: ");
    for (int i = top; i >= 0; i--) 
      printf("%d ", stack[i]);

    printf("\nTop element: %d\n", peek());

    printf("Popped element: %d\n", pop());
    printf("Popped element: %d\n", pop());

    printf("Stack is empty: %d\n", isEmpty());
    printf("Stack is full: %d\n", isFull());

    return 0;
}
