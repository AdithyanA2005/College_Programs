#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *front = NULL, *rear = NULL;

struct Node *createNode(int data) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  if (node == NULL) {
    printf("Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }
  node->data = data;
  node->next = NULL;
  return node;
}

void display() {
  printf("List: ");
  if (front == NULL) {
    printf("Empty");
  } else {
    struct Node *ptr = front;
    while (ptr != NULL) {
      printf("%d ", ptr->data);
      ptr = ptr->next;
    }
  }
  printf("\n");
}

void enqueue() {
  int data;
  printf("Enter data: ");
  scanf("%d", &data);
  struct Node *node = createNode(data);
  if (front == NULL) front = node;
  else rear->next = node;
  rear = node;
}

void dequeue() {
  if (front == NULL) {
    printf("Queue Underflow\n");
  } else {
    struct Node *temp = front;
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
  }
}

int main() {
  int doRun = 1, choice;
  printf("1 - Enqueue\n");
  printf("2 - Dequeue\n");
  printf("3 - Display\n");
  printf("4 - Exit\n");

  while(doRun) {
    printf("\nEnter choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        enqueue();
        display();
        break;
      case 2:
        dequeue();
        display();
        break;
      case 3:
        display();
        break;
      default:
        printf("Program Terminated\n");
        doRun = 0;
    }
  }
}
