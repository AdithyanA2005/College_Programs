#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct symbol {
  char label[20];
  int address;
} symtab[50];

struct opcode {
  char code[20];
  int length;
} optab[30];

int main() {
  FILE *fp, *fout, *fsym, *fopt;
  char label[20], opcode[20], operand[20];
  int locctr, start = 0, length, symcount = 0, optcount = 0, found;

  // Open files
  fp = fopen("pass-input.asm", "r");
  fout = fopen("pass-one-out.txt", "w");
  fsym = fopen("pass-symtab.txt", "w");
  fopt = fopen("pass-optab.txt", "r");

  if (fp == NULL || fout == NULL || fsym == NULL || fopt == NULL) {
    printf("Error: Cannot open one of the files\n");
    exit(0);
  }

  // Load OPTAB
  while (fscanf(fopt, "%s %d", optab[optcount].code, &optab[optcount].length) !=
         EOF) {
    optcount++;
  }

  fscanf(fp, "%s %s %s", label, opcode, operand);

  // Handle START
  if (strcmp(opcode, "START") == 0) {
    start = atoi(operand);
    locctr = start;
    fprintf(fout, "%d\t%s\t%s\t%s\n", locctr, label, opcode, operand);
    fscanf(fp, "%s %s %s", label, opcode, operand);
  } else {
    locctr = 0;
  }

  // Main loop
  while (strcmp(opcode, "END") != 0) {
    fprintf(fout, "%d\t%s\t%s\t%s\n", locctr, label, opcode, operand);

    // If label exists, add to SYMTAB
    if (strcmp(label, "**") != 0) {
      strcpy(symtab[symcount].label, label);
      symtab[symcount].address = locctr;
      symcount++;
    }

    // Check OPTAB
    found = 0;
    for (int i = 0; i < optcount; i++) {
      if (strcmp(opcode, optab[i].code) == 0) {
        locctr += optab[i].length;
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
      else if (strcmp(opcode, "BYTE") == 0)
        locctr += strlen(operand) - 3; // assume C'EOF'
      else if (strcmp(opcode, "END") == 0)
        ; // do nothing
      else
        printf("Warning: Unknown opcode %s\n", opcode);
    }

    fscanf(fp, "%s %s %s", label, opcode, operand);
  }

  // Write END line
  fprintf(fout, "%d\t%s\t%s\t%s\n", locctr, label, opcode, operand);
  length = locctr - start;

  // Write SYMTAB to file
  for (int i = 0; i < symcount; i++) {
    fprintf(fsym, "%s\t%d\n", symtab[i].label, symtab[i].address);
  }

  printf("Pass One completed.\nProgram length = %d\n", length);
  printf("Check 'output.txt' and 'symtab.txt'.\n");

  fclose(fp);
  fclose(fout);
  fclose(fsym);
  fclose(fopt);

  return 0;
}
