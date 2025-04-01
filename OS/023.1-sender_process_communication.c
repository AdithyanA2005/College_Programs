/* Process that writes to shared memory */

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHM_KEY 1234
#define SHM_SIZE 1024

int main() {
  int shmid;
  char *shared_memory;

  // Create the shared memory segment
  shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
  if (shmid < 0) {
    perror("shmget failed");
    exit(1);
  }

  // Attach the shared memory segment
  shared_memory = (char *)shmat(shmid, NULL, 0);
  if (shared_memory == (char *)-1) {
    perror("shmat failed");
    exit(1);
  }

  // Write data to the shared memory
  printf("Writer: Enter message to write to shared memory: ");
  fgets(shared_memory, SHM_SIZE, stdin);

  printf("Writer: Data written to shared memory: %s\n", shared_memory);

  // Sleep to allow reader process time to read
  printf(
      "Writer: Sleeping for 5 seconds to allow reader to access the data...\n");
  sleep(5);

  // Detach from shared memory
  if (shmdt(shared_memory) == -1) {
    perror("shmdt failed");
    exit(1);
  }

  printf("Writer: Successfully detached from shared memory\n");

  return 0;
}
