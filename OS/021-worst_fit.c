#include <stdio.h>

#define MAX_BLOCKS 100
#define MAX_PROCESSES 100

// Memory block structure
typedef struct {
    int size;
    int process_id;  // -1 means free
} MemoryBlock;

// Worst Fit allocation function
void worstFitAllocate(MemoryBlock blocks[], int num_blocks, 
                      int process_sizes[], int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        int worst_index = -1;
        int max_size = -1;
        
        // Find the largest free block that fits the process
        for (int j = 0; j < num_blocks; j++) {
            if (blocks[j].process_id == -1 && 
                blocks[j].size >= process_sizes[i]) {
                if (blocks[j].size > max_size) {
                    max_size = blocks[j].size;
                    worst_index = j;
                }
            }
        }
        
        // Allocate if a suitable block is found
        if (worst_index != -1) {
            blocks[worst_index].process_id = i;
            printf("Process %d allocated to Block %d\n", i + 1, worst_index + 1);
        } else {
            printf("Process %d cannot be allocated\n", i + 1);
        }
    }
}

// Display memory status
void displayStatus(MemoryBlock blocks[], int num_blocks) {
    printf("\nMemory Status:\n");
    printf("Block\tSize\tStatus\n");
    
    for (int i = 0; i < num_blocks; i++) {
        printf("%d\t%d\t", i + 1, blocks[i].size);
        
        if (blocks[i].process_id == -1)
            printf("Free\n");
        else
            printf("P%d\n", blocks[i].process_id + 1);
    }
}

int main() {
    MemoryBlock blocks[MAX_BLOCKS];
    int process_sizes[MAX_PROCESSES];
    int num_blocks, num_processes;
    
    // Input number of memory blocks
    printf("Enter number of memory blocks: ");
    scanf("%d", &num_blocks);
    
    // Input block sizes
    printf("Enter block sizes:\n");
    for (int i = 0; i < num_blocks; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blocks[i].size);
        blocks[i].process_id = -1;  // Mark as free
    }
    
    // Input number of processes
    printf("Enter number of processes: ");
    scanf("%d", &num_processes);
    
    // Input process sizes
    printf("Enter process sizes:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &process_sizes[i]);
    }
    
    // Perform worst-fit allocation
    worstFitAllocate(blocks, num_blocks, process_sizes, num_processes);
    
    // Display final memory status
    displayStatus(blocks, num_blocks);
    
    return 0;
}
