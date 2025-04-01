/* Process that reads from shared memory */

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 1234
#define SHM_SIZE 1024

int main() {
  int shmid;
  char *shared_memory;

  // Get the existing shared memory segment
  shmid = shmget(SHM_KEY, SHM_SIZE, 0666);
  if (shmid < 0) {
    perror("shmget failed");
    exit(1);
  }

  // Attach to the shared memory segment
  shared_memory = (char *)shmat(shmid, NULL, 0);
  if (shared_memory == (char *)-1) {
    perror("shmat failed");
    exit(1);
  }

  // Read data from the shared memory
  printf("Reader: Data read from shared memory: %s\n", shared_memory);

  // Detach from shared memory
  if (shmdt(shared_memory) == -1) {
    perror("shmdt failed");
    exit(1);
  }

  // Remove the shared memory segment
  if (shmctl(shmid, IPC_RMID, NULL) == -1) {
    perror("shmctl failed");
    exit(1);
  }

  printf("Reader: Successfully detached and removed shared memory\n");

  return 0;
}
