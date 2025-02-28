#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	int pid, pid1, pid2;
	pid = fork();
	
	if (pid == -1) {
		printf("There was a error creating the process\n");
		exit(1);
	} else if (pid == 0) {
		pid1 = getpid();
		printf("The child process Id: %d\n", pid1);
	} else {
		pid2 = getpid();
		printf("The parent process Id: %d\n", pid2);
	}
}
