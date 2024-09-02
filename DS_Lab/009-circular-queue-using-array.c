#include <stdio.h>

#define MAX_SIZE 5

int front = -1, rear = -1;
int queue[MAX_SIZE];

int enqueue(int data) {
  if ((rear + 1) % MAX_SIZE == front) {
    printf("Queue overflow\n");
    return 0;
  }

  if (front == -1)
    front = 0;
  rear = (rear + 1) % MAX_SIZE;
  queue[rear] = data;
  return 1;
}

int dequeue() {
  if (front == -1) {
    printf("Queue underflow\n");
    return 0;
  }

  if (front == rear) {
    front = rear = -1;
  } else {
    front = (front + 1) % MAX_SIZE;
  }
  return 1;
}

void display() {
  if (front == -1) {
    printf("Queue is empty\n");
  } else {
    int i = front;
    while (i != rear) {
      printf("%d ", queue[i]);
      i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", queue[rear]);
  }
}

int main() {
  int doRun = 1, temp, choice;

  printf("CIRCULAR QUEUE\n--------------\n");
  printf("1 - Enqueue\n2 - Dequeue\n3 - Display\n");

  while (doRun) {
    printf("\nEnter a choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter value: ");
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
}
