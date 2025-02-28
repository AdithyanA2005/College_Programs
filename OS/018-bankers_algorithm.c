#include <stdio.h>
#include <stdlib.h>

// Function to check if the system is in a safe state
int isSafe(int processes, int resources, int available[], int max[][resources], 
        int allocation[][resources], int need[][resources], int safeSeq[]) {
    int work[resources];
    int finish[processes];
    
    // Initialize work array with available resources
    for (int i = 0; i < resources; i++)
        work[i] = available[i];
    
    // Initialize finish array
    for (int i = 0; i < processes; i++)
        finish[i] = 0;
    
    // Find a process that can be executed
    int count = 0;
    while (count < processes) {
        int found = 0;
        for (int p = 0; p < processes; p++) {
            if (finish[p] == 0) {
                int canExecute = 1;
                
                // Check if all resources for this process can be allocated
                for (int r = 0; r < resources; r++) {
                    if (need[p][r] > work[r]) {
                        canExecute = 0;
                        break;
                    }
                }
                
                if (canExecute) {
                    // Add this process to safe sequence
                    safeSeq[count] = p;
                    
                    // Release resources
                    for (int r = 0; r < resources; r++)
                        work[r] += allocation[p][r];
                    
                    finish[p] = 1;
                    found = 1;
                    count++;
                    break;
                }
            }
        }
        
        if (found == 0) {
            // No process can be executed
            return 0;
        }
    }
    
    // System is in safe state
    return 1;
}

// Function to display resource matrices
void displayMatrix(int processes, int resources, int allocation[][resources], 
                int max[][resources], int need[][resources], int available[]) {
    printf("\nAllocation Matrix:\n");
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            printf("%d ", allocation[i][j]);
        }
        printf("\n");
    }
    
    printf("\nMaximum Need Matrix:\n");
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            printf("%d ", max[i][j]);
        }
        printf("\n");
    }
    
    printf("\nNeed Matrix (Max - Allocation):\n");
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
    
    printf("\nAvailable Resources:\n");
    for (int i = 0; i < resources; i++) {
        printf("%d ", available[i]);
    }
    printf("\n");
}

int main() {
    int processes, resources;
    
    printf("---------------------------------------------\n");
    printf("BANKER'S ALGORITHM FOR DEADLOCK AVOIDANCE\n");
    printf("---------------------------------------------\n\n");
    
    // Input number of processes and resources
    printf("Enter the number of processes: ");
    scanf("%d", &processes);
    printf("Enter the number of resource types: ");
    scanf("%d", &resources);
    
    // Dynamically allocate memory for matrices
    int (*allocation)[resources] = malloc(processes * sizeof(*allocation));
    int (*max)[resources] = malloc(processes * sizeof(*max));
    int (*need)[resources] = malloc(processes * sizeof(*need));
    int *available = malloc(resources * sizeof(int));
    int *safeSeq = malloc(processes * sizeof(int));
    
    // Input allocation matrix
    printf("\nEnter the Allocation Matrix:\n");
    for (int i = 0; i < processes; i++) {
        printf("For Process %d: ", i);
        for (int j = 0; j < resources; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }
    
    // Input maximum need matrix
    printf("\nEnter the Maximum Need Matrix:\n");
    for (int i = 0; i < processes; i++) {
        printf("For Process %d: ", i);
        for (int j = 0; j < resources; j++) {
            scanf("%d", &max[i][j]);
        }
    }
    
    // Input available resources
    printf("\nEnter the Available Resources:\n");
    for (int i = 0; i < resources; i++) {
        scanf("%d", &available[i]);
    }
    
    // Calculate need matrix
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
    
    // Display matrices
    displayMatrix(processes, resources, allocation, max, need, available);
    
    // Check if the system is in a safe state
    if (isSafe(processes, resources, available, max, allocation, need, safeSeq)) {
        printf("\nTHE SYSTEM IS IN A SAFE STATE\n");
        printf("Safe Sequence: ");
        for (int i = 0; i < processes; i++) {
            printf("P%d", safeSeq[i]);
            if (i < processes - 1)
                printf(" -> ");
        }
        printf("\n");
    } else {
        printf("\nTHE SYSTEM IS NOT IN A SAFE STATE\n");
    }
    
    // Free dynamically allocated memory
    free(allocation);
    free(max);
    free(need);
    free(available);
    free(safeSeq);
    
    return 0;
}

