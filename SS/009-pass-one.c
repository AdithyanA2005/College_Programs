#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct symbol {
  char label[20];
  int address;
} symtab[50];

struct opcode {
  char code[20]; // mnemonic
  char hex[10];  // hex value for Pass Two
  int length;    // fixed length = 3
} optab[30];

int main() {
  FILE *fp, *fout, *fsym, *fopt;
  char label[20], opcode[20], operand[20];
  int locctr = 0, start = 0, length, symcount = 0, optcount = 0, found;

  fp = fopen("pass-input.asm", "r");
  fout = fopen("pass-intermediate.txt", "w");
  fsym = fopen("pass-symtab.txt", "w");
  fopt = fopen("pass-optab.txt", "r");

  if (!fp || !fout || !fsym || !fopt) {
    printf("Error opening files.\n");
    return 1;
  }

  // Load OPTAB (mnemonic + hex, length = 3)
  while (fscanf(fopt, "%s %s", optab[optcount].code, optab[optcount].hex) !=
         EOF) {
    optab[optcount].length = 3;
    optcount++;
  }

  fscanf(fp, "%s %s %s", label, opcode, operand);

  // Handle START
  if (strcmp(opcode, "START") == 0) {
    start = atoi(operand);
    locctr = start;
    fprintf(fout, "%d\t%s\t%s\t%s\n", locctr, label, opcode, operand);
    fscanf(fp, "%s %s %s", label, opcode, operand);
  }

  // Main Pass One loop
  while (strcmp(opcode, "END") != 0) {
    fprintf(fout, "%d\t%s\t%s\t%s\n", locctr, label, opcode, operand);

    // Add label to SYMTAB if present
    if (strcmp(label, "**") != 0 && strlen(label) > 0) {
      strcpy(symtab[symcount].label, label);
      symtab[symcount].address = locctr;
      symcount++;
    }

    // Check if opcode is in OPTAB
    found = 0;
    for (int i = 0; i < optcount; i++) {
      if (strcmp(opcode, optab[i].code) == 0) {
        locctr += optab[i].length; // always +3
        found = 1;
        break;
      }
    }

    // If not in OPTAB, check assembler directives
    if (!found) {
      if (strcmp(opcode, "WORD") == 0)
        locctr += 3;
      else if (strcmp(opcode, "RESW") == 0)
        locctr += 3 * atoi(operand);
      else if (strcmp(opcode, "RESB") == 0)
        locctr += atoi(operand);
      else if (strcmp(opcode, "BYTE") == 0) {
        if (operand[0] == 'C')
          locctr += strlen(operand) - 3;
        else if (operand[0] == 'X')
          locctr += (strlen(operand) - 3) / 2;
      } else {
        printf("Warning: Unknown opcode %s\n", opcode);
      }
    }

    fscanf(fp, "%s %s %s", label, opcode, operand);
  }

  // Write END line
  fprintf(fout, "%d\t%s\t%s\t%s\n", locctr, label, opcode, operand);

  // Write SYMTAB
  for (int i = 0; i < symcount; i++) {
    fprintf(fsym, "%s\t%d\n", symtab[i].label, symtab[i].address);
  }

  length = locctr - start;
  printf("Pass One completed. Program length = %d\n", length);

  fclose(fp);
  fclose(fout);
  fclose(fsym);
  fclose(fopt);

  return 0;
}
