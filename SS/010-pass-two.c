#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct symbol {
  char label[20];
  int address;
} symtab[50];

struct opcode {
  char code[20];
  char hex[10];
} optab[30];

int lookup_sym(char *label, int symcount) {
  for (int i = 0; i < symcount; i++) {
    if (strcmp(symtab[i].label, label) == 0)
      return symtab[i].address;
  }
  return -1; // not found
}

char *lookup_op(char *opcode, int optcount) {
  for (int i = 0; i < optcount; i++) {
    if (strcmp(optab[i].code, opcode) == 0)
      return optab[i].hex;
  }
  return NULL;
}

int main() {
  FILE *fp, *fopt, *fsym, *fobj;
  char label[20], opcode[20], operand[20];
  int loc, start = 0, length = 0, symcount = 0, optcount = 0;

  fp = fopen("pass-intermediate.txt", "r");
  fopt = fopen("pass-optab.txt", "r");
  fsym = fopen("pass-symtab.txt", "r");
  fobj = fopen("pass-object-program.txt", "w");

  if (!fp || !fopt || !fsym || !fobj) {
    printf("Error opening files.\n");
    return 1;
  }

  // Load OPTAB
  while (fscanf(fopt, "%s %s", optab[optcount].code, optab[optcount].hex) !=
         EOF)
    optcount++;

  // Load SYMTAB
  while (fscanf(fsym, "%s %d", symtab[symcount].label,
                &symtab[symcount].address) != EOF)
    symcount++;

  // Read first line (START)
  fscanf(fp, "%d %s %s %s", &loc, label, opcode, operand);
  if (strcmp(opcode, "START") == 0) {
    start = loc;
    fprintf(fobj, "H^%-6s^%06X^%06X\n", label, loc,
            0); // program length will be updated later
    fscanf(fp, "%d %s %s %s", &loc, label, opcode, operand);
  }

  // Start text record
  fprintf(fobj, "T^%06X^", loc);
  int text_len = 0;

  while (strcmp(opcode, "END") != 0) {
    char objcode[10] = "";

    char *ophex = lookup_op(opcode, optcount);
    if (ophex) {
      int addr = 0;
      if (strlen(operand) > 0 && strcmp(operand, "**") != 0)
        addr = lookup_sym(operand, symcount);
      sprintf(objcode, "%s%04X", ophex, addr);
    } else if (strcmp(opcode, "WORD") == 0) {
      sprintf(objcode, "%06d", atoi(operand));
    } else if (strcmp(opcode, "BYTE") == 0) {
      if (operand[0] == 'C') {
        int len = strlen(operand) - 3;
        char temp[3];
        strcpy(objcode, "");
        for (int i = 0; i < len; i++) {
          sprintf(temp, "%02X", operand[i + 2]);
          strcat(objcode, temp);
        }
      } else if (operand[0] == 'X') {
        strncpy(objcode, operand + 2, strlen(operand) - 3);
        objcode[strlen(operand) - 3] = '\0';
      }
    } else if (strcmp(opcode, "RESW") == 0 || strcmp(opcode, "RESB") == 0) {
      // End current text record, start new
      if (text_len > 0) {
        fprintf(fobj, "^%02X\n", text_len);
        text_len = 0;
      }
      fscanf(fp, "%d %s %s %s", &loc, label, opcode, operand);
      continue;
    }

    fprintf(fobj, "%s^", objcode);
    text_len += strlen(objcode) / 2;

    fscanf(fp, "%d %s %s %s", &loc, label, opcode, operand);
  }

  // End last text record
  if (text_len > 0)
    fprintf(fobj, "%02X\n", text_len);

  // End record
  fprintf(fobj, "E^%06X\n", start);

  fclose(fp);
  fclose(fopt);
  fclose(fsym);
  fclose(fobj);

  printf("Pass Two completed. Object program generated.\n");
  return 0;
}
