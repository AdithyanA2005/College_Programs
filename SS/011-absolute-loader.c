// 1. Open the object file.
// 2. Create memory of size 4096 and set all bytes to 0.
// 3. Read the file line by line:
//
//    * If it’s a header (`H`), get the starting address.
//    * If it’s a text record (`T`), read the address and store each byte from
//    the record into memory at that address.
//    * If it’s the end record (`E`), stop reading.
// 4. Close the file.
// 5. Print all non-zero memory locations.
// 6. Print “Program loaded successfully.”

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEMORY_SIZE 4096 // sufficient memory

int main() {
  FILE *fobj = fopen("pass-object-program.txt", "r");
  if (!fobj) {
    printf("Error opening object file.\n");
    return 1;
  }

  unsigned char memory[MEMORY_SIZE];
  for (int i = 0; i < MEMORY_SIZE; i++)
    memory[i] = 0;

  char line[1024];
  int start_addr = 0;

  while (fgets(line, sizeof(line), fobj)) {
    if (line[0] == 'H') {
      // Header: H^PROG^START^LENGTH
      sscanf(line, "H^%*6s^%X", &start_addr);
      printf("Program starts at: %X\n", start_addr);
    } else if (line[0] == 'T') {
      // Text record: T^ADDR^OBJ...
      char *token = strtok(line, "^"); // T
      token = strtok(NULL, "^");       // Start address
      int addr = (int)strtol(token, NULL, 16);
      token = strtok(NULL, "^"); // Length (ignore)
      while ((token = strtok(NULL, "^")) != NULL) {
        if (strlen(token) == 0)
          continue;
        unsigned int byte = (unsigned int)strtol(token, NULL, 16);
        if (addr >= MEMORY_SIZE) {
          printf("Memory overflow at %X\n", addr);
          break;
        }
        memory[addr++] = (unsigned char)byte;
      }
    } else if (line[0] == 'E') {
      // End record
      break;
    }
  }

  fclose(fobj);

  // Display loaded memory
  printf("\nMemory Content:\n");
  for (int i = 0; i < MEMORY_SIZE; i++) {
    if (memory[i] != 0)
      printf("%04X : %02X\n", i, memory[i]);
  }

  printf("\nProgram loaded successfully!\n");
  return 0;
}
