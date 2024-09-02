#include <stdio.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

int enqueue(int data) {
  if (rear == MAX_SIZE - 1) {
    printf("Queue Overflow\n");
    return 0;
  }

  if (front == -1) front = 0;
  queue[++rear] = data;
  return 1;
}

int dequeue() {
  if (front == -1) {
    printf("Queue Underflow\n");
    return 0;
  }

  if (front == rear) front = rear = -1;
  else front++;
  return 1;
}

void display() {
  if (front == -1) {
    printf("Queue is empty\n");
  } else {
    printf("Queue: ");
    for (int i = front; i <= rear; i++) {
      printf("%d ", queue[i]);
    }
    printf("\n");
  }
}

int main() {
  int choice, temp, doRun = 1;

  printf("QUEUE\n-----\n");
  printf("1 - Enqueue\n2 - Dequeue\n3 - Display\n");

  while (doRun) {
    printf("\nEnter Choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter data: ");
      scanf("%d", &temp);
      if (enqueue(temp))
        display();
      break;
    case 2:
      if (dequeue())
        display();
      break;
    case 3:
      display();
      break;
    default:
      doRun = 0;
    }
  }

  return 0;
}
