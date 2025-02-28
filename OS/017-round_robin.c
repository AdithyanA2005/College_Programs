#include <stdio.h>

#define MAX_PROCESSES 10

void roundRobin(int n, int burstTime[], int timeQuantum) {
  int waitingTime[MAX_PROCESSES] = {0};
  int turnaroundTime[MAX_PROCESSES] = {0};
  int remainingTime[MAX_PROCESSES];
  int i, time = 0, completed = 0;
  float totWaitingTime = 0, totTurnaroundTime = 0;

  // Initialize remaining time with burst time
  for (i = 0; i < n; i++) {
    remainingTime[i] = burstTime[i];
  }

  // Process all processes until completion
  while (completed != n) {
    int allDone = 1;

    // Loop through all processes
    for (i = 0; i < n; i++) {
      if (remainingTime[i] > 0) {
        allDone = 0; // Some process is still pending

        if (remainingTime[i] > timeQuantum) {
          // Process for time quantum
          time += timeQuantum;
          remainingTime[i] -= timeQuantum;
        } else {
          // Process for remaining time and mark as completed
          time += remainingTime[i];
          waitingTime[i] = time - burstTime[i];
          remainingTime[i] = 0;
          completed++;
        }
      }
    }

    // If all processes are done, break
    if (allDone) {
      break;
    }
  }

  // Calculate turnaround time and averages
  for (i = 0; i < n; i++) {
    turnaroundTime[i] = burstTime[i] + waitingTime[i];
    totWaitingTime += waitingTime[i];
    totTurnaroundTime += turnaroundTime[i];
  }

  // Print results
  printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
  for (i = 0; i < n; i++) {
    printf("%d\t%d\t\t%d\t\t%d\n", i + 1, burstTime[i], waitingTime[i],
           turnaroundTime[i]);
  }

  printf("\nTotal Waiting Time: %.2f\n", totWaitingTime);
  printf("Average Waiting Time: %.2f\n", totWaitingTime / n);
  printf("Total Turnaround Time: %.2f\n", totTurnaroundTime);
  printf("Average Turnaround Time: %.2f\n", totTurnaroundTime / n);
}

int main() {
  int n, i, timeQuantum;
  int burstTime[MAX_PROCESSES];

  printf("Enter the number of processes (max %d): ", MAX_PROCESSES);
  scanf("%d", &n);

  if (n > MAX_PROCESSES || n <= 0) {
    printf("Invalid number of processes\n");
    return 1;
  }

  printf("Enter burst time for each process:\n");
  for (i = 0; i < n; i++) {
    printf("Process %d: ", i + 1);
    scanf("%d", &burstTime[i]);

    if (burstTime[i] <= 0) {
      printf("Burst time must be positive\n");
      return 1;
    }
  }

  printf("Enter time quantum: ");
  scanf("%d", &timeQuantum);

  if (timeQuantum <= 0) {
    printf("Time quantum must be positive\n");
    return 1;
  }

  printf("\nRound Robin Scheduling Algorithm\n");
  roundRobin(n, burstTime, timeQuantum);

  return 0;
}
