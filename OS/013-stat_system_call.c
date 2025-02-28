#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

int main() {
  char filename[256];
  struct stat fileStat;

  // Get the name fo the file
  printf("Enter file name: ");
  scanf("%255s", filename);

  // Get file stats
  if (stat(filename, &fileStat) == -1) {
    perror("Stat Failed");
    exit(1);
  }

  // Display the stats
  printf("File: %s\n", filename);
  printf("Block size: %lld bytes\n", (long long)fileStat.st_blksize);
  printf("No of blocks: %lld \n", (long long)fileStat.st_blocks);
  printf("No of links: %ld\n", (long)fileStat.st_nlink);
  printf("UserId: %d\n", fileStat.st_uid);
  printf("Permissions: : %d\n", fileStat.st_mode);
  printf("Last modified: %s", ctime(&fileStat.st_mtime));
  printf("Last acess time: %s", ctime(&fileStat.st_atime));
}
