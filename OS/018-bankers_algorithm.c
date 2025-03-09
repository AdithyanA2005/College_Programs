#include <stdio.h>

#define MAX_PROCESSES 100
#define MAX_RESOURCES 100

int isSafe(int processes, int resources, int available[],
           int max[][MAX_RESOURCES], int allocation[][MAX_RESOURCES],
           int need[][MAX_RESOURCES], int safeSeq[]) {
  int work[MAX_RESOURCES], finish[MAX_PROCESSES] = {0};
  for (int i = 0; i < resources; i++)
    work[i] = available[i];

  int count = 0;
  while (count < processes) {
    int found = 0;
    for (int p = 0; p < processes; p++) {
      if (!finish[p]) {
        int canExecute = 1;
        for (int r = 0; r < resources; r++) {
          if (need[p][r] > work[r]) {
            canExecute = 0;
            break;
          }
        }

        if (canExecute) {
          safeSeq[count++] = p;
          for (int r = 0; r < resources; r++)
            work[r] += allocation[p][r];
          finish[p] = 1;
          found = 1;
          break;
        }
      }
    }

    if (!found)
      return 0; // No process can be executed
  }
  return 1; // System is in safe state
}

int main() {
  int processes, resources;

  printf("Enter number of processes: ");
  scanf("%d", &processes);
  printf("Enter number of resource types: ");
  scanf("%d", &resources);

  int allocation[MAX_PROCESSES][MAX_RESOURCES] = {0},
      max[MAX_PROCESSES][MAX_RESOURCES] = {0},
      need[MAX_PROCESSES][MAX_RESOURCES] = {0}, available[MAX_RESOURCES] = {0},
      safeSeq[MAX_PROCESSES] = {0};

  printf("Enter Allocation Matrix:\n");
  for (int i = 0; i < processes; i++)
    for (int j = 0; j < resources; j++)
      scanf("%d", &allocation[i][j]);

  printf("\nEnter Maximum Need Matrix:\n");
  for (int i = 0; i < processes; i++)
    for (int j = 0; j < resources; j++)
      scanf("%d", &max[i][j]);

  printf("\nEnter Available Resources:\n");
  for (int i = 0; i < resources; i++)
    scanf("%d", &available[i]);

  // Calculate Need matrix
  for (int i = 0; i < processes; i++)
    for (int j = 0; j < resources; j++)
      need[i][j] = max[i][j] - allocation[i][j];

  if (isSafe(processes, resources, available, max, allocation, need, safeSeq)) {
    printf("\nTHE SYSTEM IS IN A SAFE STATE\nSafe Sequence: ");
    for (int i = 0; i < processes; i++) {
      printf("P%d", safeSeq[i]);
      if (i < processes - 1)
        printf(" -> ");
    }
    printf("\n");
  } else {
    printf("\nTHE SYSTEM IS NOT IN A SAFE STATE\n");
  }

  return 0;
}
