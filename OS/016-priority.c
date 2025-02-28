#include <stdio.h>

int main() {
  int n, i, j;
  int burst_time[100], waiting_time[100], priority[100];
  int turnaround_time[100], process[100];
  float tot_waiting = 0, tot_turnaround = 0;

  printf("Enter the number of processes: ");
  scanf("%d", &n);

  // Input burst times and initialize process numbers
  for (i = 0; i < n; i++) {
    printf("Enter burst time and priority for Process %d: ", i + 1);
    scanf("%d", &burst_time[i]);
    scanf("%d", &priority[i]);
    process[i] = i + 1;
  }

  // Sort by priority (bubble sort)
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (priority[j] > priority[j + 1]) {
        // Swap priorities numbers
        priority[j] = priority[j] ^ priority[j + 1];
        priority[j + 1] = priority[j] ^ priority[j + 1];
        priority[j] = priority[j] ^ priority[j + 1];

        // Swap burst times
        burst_time[j] = burst_time[j] ^ burst_time[j + 1];
        burst_time[j + 1] = burst_time[j] ^ burst_time[j + 1];
        burst_time[j] = burst_time[j] ^ burst_time[j + 1];

        // Swap process numbers
        process[j] = process[j] ^ process[j + 1];
        process[j + 1] = process[j] ^ process[j + 1];
        process[j] = process[j] ^ process[j + 1];
      }
    }
  }

  // Calculate waiting time
  waiting_time[0] = 0;
  for (i = 1; i < n; i++) {
    waiting_time[i] = waiting_time[i - 1] + burst_time[i - 1];
    tot_waiting += waiting_time[i];
  }

  // Calculate turnaround time
  for (i = 0; i < n; i++) {
    turnaround_time[i] = waiting_time[i] + burst_time[i];
    tot_turnaround += turnaround_time[i];
  }

  // Calculate averages
  float avg_waiting = tot_waiting / n;
  float avg_turnaround = tot_turnaround / n;

  // Display results
  printf("\nProcess Scheduling Details:\n");
  printf("------------------------\n");
  printf("Process\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");

  for (i = 0; i < n; i++)
    printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", process[i], priority[i], burst_time[i],
           waiting_time[i], turnaround_time[i]);

  printf("\nTotal Waiting Time: %.2f\n", tot_waiting);
  printf("Average Waiting Time: %.2f\n", avg_waiting);
  printf("Total Turnaround Time: %.2f\n", tot_turnaround);
  printf("Average Turnaround Time: %.2f\n", avg_turnaround);

  return 0;
}
