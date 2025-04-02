#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

#define BUFFER_SIZE 5

// Shared buffer
int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;

// Semaphores
sem_t empty;
sem_t full;
sem_t mutex;

// Function to produce an item
void produce() {
  int item;

  // Check if buffer is full
  int empty_value;
  sem_getvalue(&empty, &empty_value);
  if (empty_value == 0) {
    printf("Buffer is full! Cannot produce.\n");
    return;
  }

  // Get user input
  printf("Enter a value to produce: ");
  scanf("%d", &item);

  // Wait for empty slot and lock buffer
  sem_wait(&empty);
  sem_wait(&mutex);

  // Add item to buffer
  buffer[in] = item;
  in = (in + 1) % BUFFER_SIZE;
  printf("Produced: %d\n", item);

  // Release lock and signal item available
  sem_post(&mutex);
  sem_post(&full);
}

// Function to consume an item
void consume() {
  // Check if buffer is empty
  int full_value;
  sem_getvalue(&full, &full_value);
  if (full_value == 0) {
    printf("Buffer is empty! Nothing to consume.\n");
    return;
  }

  // Wait for item and lock buffer
  sem_wait(&full);
  sem_wait(&mutex);

  // Remove item from buffer
  int item = buffer[out];
  out = (out + 1) % BUFFER_SIZE;
  printf("Consumed: %d\n", item);

  // Release lock and signal empty slot
  sem_post(&mutex);
  sem_post(&empty);
}

int main() {
  int choice;

  // Initialize semaphores
  sem_init(&empty, 0, BUFFER_SIZE);
  sem_init(&full, 0, 0);
  sem_init(&mutex, 0, 1);

  while (1) {
    printf("\nMenu:\n");
    printf("1. Produce\n");
    printf("2. Consume\n");
    printf("3. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      produce();
      break;
    case 2:
      consume();
      break;
    case 3:
      sem_destroy(&empty);
      sem_destroy(&full);
      sem_destroy(&mutex);
      return 0;
    default:
      printf("Invalid choice!\n");
    }
  }

  return 0;
}
