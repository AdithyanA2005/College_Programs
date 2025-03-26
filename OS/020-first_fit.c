#include <stdbool.h>
#include <stdio.h>

#define MAX_PARTITIONS 100

// Simplified structure for memory partition
typedef struct {
  int size;       // Size of the partition
  int process_id; // ID of the process (-1 if free)
} Partition;

// First Fit allocation function
bool allocateMemory(Partition *partitions, int num_partitions, int process_id,
                    int process_size) {
  for (int i = 0; i < num_partitions; i++) {
    // Check if partition is free and large enough
    if (partitions[i].process_id == -1 && partitions[i].size >= process_size) {
      partitions[i].process_id = process_id;
      return true;
    }
  }
  return false;
}

// Display memory allocation status
void showMemoryStatus(Partition *partitions, int num_partitions) {
  printf("\nMemory Allocation Status:\n");
  printf("Partition\tSize\tProcess\n");

  for (int i = 0; i < num_partitions; i++) {
    printf("%d\t\t%d\t", i, partitions[i].size);

    if (partitions[i].process_id == -1)
      printf("Free\n");
    else
      printf("P%d\n", partitions[i].process_id);
  }
}

int main() {
  Partition partitions[MAX_PARTITIONS];
  int num_partitions, num_processes;

  // Input number of partitions
  printf("Enter number of memory partitions: ");
  scanf("%d", &num_partitions);

  // Input partition sizes
  for (int i = 0; i < num_partitions; i++) {
    printf("Enter size for Partition %d: ", i);
    scanf("%d", &partitions[i].size);
    partitions[i].process_id = -1; // Mark as free initially
  }

  // Input and allocate processes
  printf("\nEnter number of processes: ");
  scanf("%d", &num_processes);

  for (int i = 0; i < num_processes; i++) {
    int process_size;
    printf("Enter size for Process %d: ", i);
    scanf("%d", &process_size);

    if (allocateMemory(partitions, num_partitions, i, process_size)) {
      printf("Process %d allocated successfully\n", i);
    } else {
      printf("Process %d could not be allocated\n", i);
    }

    showMemoryStatus(partitions, num_partitions);
  }

  return 0;
}
