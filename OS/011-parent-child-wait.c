#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pid = fork();
    
    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }
    else if (pid == 0) {
        char *args[] = {"/bin/ls", NULL};
        execv("/bin/ls", args);
        
        perror("execv failed");
        exit(1);
    }
    else {
        int status;
        wait(&status);
        printf("Parent Finished\n");
    }
    
    return 0;
}

