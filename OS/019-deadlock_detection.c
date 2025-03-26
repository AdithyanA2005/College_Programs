#include <stdbool.h>
#include <stdio.h>

#define MAX_PROCESSES 100
#define MAX_RESOURCES 100

// Function to check if a process can be executed with available resources
bool canExecute(int process, int *available,
                int request[MAX_PROCESSES][MAX_RESOURCES],
                int allocation[MAX_PROCESSES][MAX_RESOURCES], int n_resources) {
  // Check if all resources needed by the process are available
  for (int j = 0; j < n_resources; j++) {
    if (request[process][j] > available[j])
      return false;
  }
  return true;
}

// Function to detect deadlock using resource allocation graph approach
void detectDeadlock(int n_processes, int n_resources,
                    int allocation[MAX_PROCESSES][MAX_RESOURCES],
                    int request[MAX_PROCESSES][MAX_RESOURCES], int *available) {
  // Initialize work array equal to available resources
  int work[MAX_RESOURCES];
  for (int i = 0; i < n_resources; i++) {
    work[i] = available[i];
  }

  // Initialize finish array for each process
  bool finish[MAX_PROCESSES] = {false};

  // Find an unfinished process that can execute with current work resources
  bool found;
  do {
    found = false;
    for (int i = 0; i < n_processes; i++) {
      if (!finish[i] && canExecute(i, work, request, allocation, n_resources)) {
        // Process i can complete execution
        found = true;
        finish[i] = true;

        // Release allocated resources
        for (int j = 0; j < n_resources; j++) {
          work[j] += allocation[i][j];
        }

        break;
      }
    }
  } while (found);

  // Check for deadlock
  bool deadlock = false;
  printf("\nDeadlock Detection Result:\n");
  for (int i = 0; i < n_processes; i++) {
    if (!finish[i]) {
      if (!deadlock) {
        printf("System is in deadlock state.\n");
        printf("Deadlocked processes: ");
        deadlock = true;
      }
      printf("P%d ", i);
    }
  }

  if (!deadlock) {
    printf("No deadlock detected in the system.\n");
  } else {
    printf("\n");
  }
}

int main() {
  int n_processes, n_resources;
  int allocation[MAX_PROCESSES][MAX_RESOURCES];
  int request[MAX_PROCESSES][MAX_RESOURCES];
  int available[MAX_RESOURCES];

  // Get number of processes and resources
  printf("Enter number of processes: ");
  scanf("%d", &n_processes);
  printf("Enter number of resources: ");
  scanf("%d", &n_resources);

  // Input validation
  if (n_processes > MAX_PROCESSES || n_resources > MAX_RESOURCES) {
    printf("Error: Number of processes or resources exceeds maximum limit.\n");
    return 1;
  }

  // Input allocation matrix
  printf("\nEnter allocation matrix:\n");
  for (int i = 0; i < n_processes; i++) {
    printf("For process P%d: ", i);
    for (int j = 0; j < n_resources; j++) {
      scanf("%d", &allocation[i][j]);
    }
  }

  // Input request matrix
  printf("\nEnter request matrix:\n");
  for (int i = 0; i < n_processes; i++) {
    printf("For process P%d: ", i);
    for (int j = 0; j < n_resources; j++) {
      scanf("%d", &request[i][j]);
    }
  }

  // Input available resources
  printf("\nEnter available resources: ");
  for (int i = 0; i < n_resources; i++) {
    scanf("%d", &available[i]);
  }

  // Call deadlock detection function
  detectDeadlock(n_processes, n_resources, allocation, request, available);

  return 0;
}
