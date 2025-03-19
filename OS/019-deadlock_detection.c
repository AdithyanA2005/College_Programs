#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  // For bool type (C99 standard)

// Function to check if a process can be executed with available resources
bool canExecute(int process, int *available, int **request, int **allocation, int n_resources) {
    // Check if all resources needed by the process are available
    for (int j = 0; j < n_resources; j++) {
        if (request[process][j] > available[j])
            return false;
    }
    return true;
}

// Function to detect deadlock using resource allocation graph approach
void detectDeadlock(int n_processes, int n_resources, int **allocation, int **request, int *available) {
    // Initialize work array equal to available resources
    int *work = (int *)malloc(n_resources * sizeof(int));
    for (int i = 0; i < n_resources; i++) {
        work[i] = available[i];
    }
    
    // Initialize finish array for each process
    bool *finish = (bool *)malloc(n_processes * sizeof(bool));
    for (int i = 0; i < n_processes; i++) {
        finish[i] = false;
    }
    
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
    
    // Free allocated memory
    free(work);
    free(finish);
}

int main() {
    int n_processes, n_resources;
    
    // Get number of processes and resources
    printf("Enter number of processes: ");
    scanf("%d", &n_processes);
    printf("Enter number of resources: ");
    scanf("%d", &n_resources);
    
    // Dynamically allocate memory for matrices
    int **allocation = (int **)malloc(n_processes * sizeof(int *));
    int **request = (int **)malloc(n_processes * sizeof(int *));
    int *available = (int *)malloc(n_resources * sizeof(int));
    
    // Allocate memory for each row
    for (int i = 0; i < n_processes; i++) {
        allocation[i] = (int *)malloc(n_resources * sizeof(int));
        request[i] = (int *)malloc(n_resources * sizeof(int));
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
    
    // Free allocated memory
    for (int i = 0; i < n_processes; i++) {
        free(allocation[i]);
        free(request[i]);
    }
    free(allocation);
    free(request);
    free(available);
    
    return 0;
}

