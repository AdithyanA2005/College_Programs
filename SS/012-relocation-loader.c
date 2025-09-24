#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEMORY_SIZE 4096

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
  int start_addr = 0, load_addr = 0;

  // Ask user where to load program
  printf("Enter loading address (hex): ");
  scanf("%x", &load_addr);

  while (fgets(line, sizeof(line), fobj)) {
    if (line[0] == 'H') {
      // Header record
      sscanf(line, "H^%*6s^%X", &start_addr);
      printf("Program original start: %X, loaded at: %X\n", start_addr,
             load_addr);
    } else if (line[0] == 'T') {
      // Text record
      char *token = strtok(line, "^"); // T
      token = strtok(NULL, "^");       // Start address
      int addr = (int)strtol(token, NULL, 16) + load_addr;
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
    } else if (line[0] == 'M') {
      // Modification record
      int mod_addr, length;
      sscanf(line, "M^%X^%d", &mod_addr, &length);

      // Adjust address by relocation factor
      int actual_addr = mod_addr + load_addr;
      int value = (memory[actual_addr] << 8) | memory[actual_addr + 1];
      value += load_addr; // relocation
      memory[actual_addr] = (value >> 8) & 0xFF;
      memory[actual_addr + 1] = value & 0xFF;
    } else if (line[0] == 'E') {
      break;
    }
  }

  fclose(fobj);

  // Display loaded memory
  printf("\nMemory Content after Relocation:\n");
  for (int i = 0; i < MEMORY_SIZE; i++) {
    if (memory[i] != 0)
      printf("%04X : %02X\n", i, memory[i]);
  }

  printf("\nProgram relocated and loaded successfully!\n");
  return 0;
}
