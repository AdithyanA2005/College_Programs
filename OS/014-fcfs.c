#include <stdio.h>

int main() {
  int n;

  // Get the number of processes
  printf("Enter the number of processes: ");
  scanf("%d", &n);

  // Arrays to store information
  int burst_time[n];
  int waiting_time[n];
  int turnaround_time[n];

  // Input burst time for each process
  for (int i = 0; i < n; i++) {
    printf("Enter burst time for Process %d: ", i + 1);
    scanf("%d", &burst_time[i]);
  }

  // Calculate waiting time for each process
  waiting_time[0] = 0; // first process has 0 waiting time
  for (int i = 1; i < n; i++) {
    waiting_time[i] = waiting_time[i - 1] + burst_time[i - 1];
  }

  // Calculate turnaround time for each process
  for (int i = 0; i < n; i++) {
    turnaround_time[i] = waiting_time[i] + burst_time[i];
  }

  // Calculate total waiting time and total turnaround time
  float total_waiting_time = 0, total_turnaround_time = 0;
  for (int i = 0; i < n; i++) {
    total_waiting_time += waiting_time[i];
    total_turnaround_time += turnaround_time[i];
  }

  // Display process information
  printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
  for (int i = 0; i < n; i++) {
    printf("P%d\t%d\t\t%d\t\t%d\n", i + 1, burst_time[i], waiting_time[i],
           turnaround_time[i]);
  }

  // Display averages
  printf("\nTotal Waiting Time: %.2f", total_waiting_time);
  printf("\nAverage Waiting Time: %.2f", total_waiting_time / n);
  printf("\nTotal Turnaround Time: %.2f", total_turnaround_time);
  printf("\nAverage Turnaround Time: %.2f\n", total_turnaround_time / n);

  return 0;
}
