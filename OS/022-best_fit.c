#include <stdio.h>

#define MAX_PARTITIONS 10
#define MAX_PROCESSES 10
#define MAX_MEMORY 1000

// Memory partition structure
typedef struct {
  int size;
  int process_id;
} Partition;

// Process structure
typedef struct {
  int size;
  int allocated;
} Process;

// Best Fit allocation function
void bestFitAllocate(Partition partitions[], int num_partitions,
                     Process processes[], int num_processes) {
  for (int i = 0; i < num_processes; i++) {
    int best_index = -1;
    int smallest_fit = MAX_MEMORY;

    // Find smallest partition that fits the process
    for (int j = 0; j < num_partitions; j++) {
      if (partitions[j].process_id == -1 &&
          partitions[j].size >= processes[i].size) {
        if (partitions[j].size < smallest_fit) {
          best_index = j;
          smallest_fit = partitions[j].size;
        }
      }
    }

    // Allocate if a suitable partition is found
    if (best_index != -1) {
      partitions[best_index].process_id = i;
      processes[i].allocated = 1;
    }
  }
}

// Display allocation status
void displayStatus(Partition partitions[], int num_partitions,
                   Process processes[], int num_processes) {
  printf("\nAllocation Status:\n");
  printf("Partition\tSize\tProcess\n");

  for (int i = 0; i < num_partitions; i++) {
    printf("%d\t\t%d\t", i, partitions[i].size);

    if (partitions[i].process_id != -1)
      printf("P%d\n", partitions[i].process_id);
    else
      printf("Free\n");
  }
}

int main() {
  Partition partitions[MAX_PARTITIONS];
  Process processes[MAX_PROCESSES];
  int num_partitions, num_processes;

  // Input number of partitions and processes
  printf("Enter number of memory partitions: ");
  scanf("%d", &num_partitions);
  printf("Enter number of processes: ");
  scanf("%d", &num_processes);

  // Input partition sizes
  printf("Enter partition sizes:\n");
  for (int i = 0; i < num_partitions; i++) {
    printf("Partition %d: ", i);
    scanf("%d", &partitions[i].size);
    partitions[i].process_id = -1; // Mark as free
  }

  // Input process sizes
  printf("Enter process sizes:\n");
  for (int i = 0; i < num_processes; i++) {
    printf("Process %d: ", i);
    scanf("%d", &processes[i].size);
    processes[i].allocated = 0;
  }

  // Perform best-fit allocation
  bestFitAllocate(partitions, num_partitions, processes, num_processes);

  // Display allocation results
  displayStatus(partitions, num_partitions, processes, num_processes);

  return 0;
}
