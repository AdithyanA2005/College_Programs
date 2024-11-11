#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node * next;
};

struct Node * top = NULL;

void display() {
  printf("Stack: ");
  if (top == NULL) {
    printf("Empty");
  } else {
    struct Node * ptr = top;
    while (ptr != NULL) {
      printf("%d ", ptr->data);
      ptr = ptr->next;
    }
  }
  printf("\n");
}

void push() {
  int data;
  printf("Enter data: ");
  scanf("%d", &data);
  struct Node * node = (struct Node *)malloc(sizeof(struct Node));
  if (node == NULL) {
    printf("Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }
  node->data = data;
  node->next = top;
  top = node;
}

void pop() {
  if (top == NULL) {
    printf("Stack Underflow\n");
  } else {
    struct Node * temp = top;
    top = top->next;
    free(temp);
  }
}

int main() {
  int doRun = 1, choice;
  printf("1 - Push\n");
  printf("2 - Pop\n");
  printf("3 - Display\n");
  printf("4 - Exit\n");

  while (doRun) {
    printf("\nEnter choice: ");
    scanf("%d", &choice);
    switch(choice) {
      case 1:
        push();
        display();
        break;
      case 2:
        pop();
        display();
        break;
      case 3:
        display();
        break;
      default:
        doRun = 0;
        printf("Program Terminated\n");
    }
  }
}

