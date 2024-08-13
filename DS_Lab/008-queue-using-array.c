#include <stdio.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int data) {
  if (rear == MAX_SIZE - 1) {
    printf("Queue Overflow\n");
    return;
  }

  if (front == -1) {
    front = 0;
  }

  queue[++rear] = data;
}

int dequeue() {
  if (front == -1) {
    printf("Queue Underflow\n");
    return -1;
  }

  int data = queue[front];

  if (front == rear)
    front = rear = -1;
  else
    front++;

  return data;
}

int peek() {
  if (front == -1) {
    printf("Queue is empty\n");
    return -1;
  }
  return queue[front];
}

int isEmpty() { return front == -1; }

int isFull() { return rear == MAX_SIZE - 1; }

int main() {
  enqueue(10);
  enqueue(20);
  enqueue(30);

  printf("The queue is: ");
  for (int i = front; i <= rear; i++)
    printf("%d ", queue[i]);

  printf("\nFront element: %d\n", peek());

  printf("Dequeued element: %d\n", dequeue());
  printf("Dequeued element: %d\n", dequeue());

  printf("Queue is empty: %d\n", isEmpty());
  printf("Queue is full: %d\n", isFull());

  return 0;
}
