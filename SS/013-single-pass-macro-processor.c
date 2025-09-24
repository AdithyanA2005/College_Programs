/* single-pass macro processor - small & working (no args) */
#include <stdio.h>
#include <string.h>

#define MAX_MACROS 20
#define MAX_LINES 200
#define MAX_LINE 128

typedef struct {
  char name[32];
  char body[MAX_LINES][MAX_LINE];
  int n;
} Macro;

Macro M[MAX_MACROS];
int mcount = 0;

int find_macro(const char *s) {
  for (int i = 0; i < mcount; i++)
    if (strcmp(M[i].name, s) == 0)
      return i;
  return -1;
}

int main(void) {
  FILE *in = fopen("macro-input.txt", "r");
  FILE *out = fopen("macro-output.txt", "w");
  if (!in) {
    perror("macro-input.txt");
    return 1;
  }
  if (!out) {
    perror("macro-output.txt");
    fclose(in);
    return 1;
  }

  char line[MAX_LINE], t1[32], t2[32];

  while (fgets(line, sizeof line, in)) {
    int toks = sscanf(line, "%31s %31s", t1, t2);
    if (toks == 0) {
      fputs("\n", out);
      continue;
    }

    /* Macro definition: NAME MACRO */
    if (toks >= 2 && strcmp(t2, "MACRO") == 0) {
      if (mcount >= MAX_MACROS) {
        fprintf(stderr, "macro table full\n");
        break;
      }
      strcpy(M[mcount].name, t1);
      M[mcount].n = 0;
      while (fgets(line, sizeof line, in)) {
        int t = sscanf(line, "%31s", t1);
        if (t >= 1 && strcmp(t1, "MEND") == 0)
          break;
        if (M[mcount].n < MAX_LINES)
          strcpy(M[mcount].body[M[mcount].n++], line);
      }
      mcount++;
      continue;
    }

    /* Macro call: either token1 is macro or token2 is macro (label present) */
    int idx = find_macro(t1);
    if (idx >= 0) {
      for (int i = 0; i < M[idx].n; i++)
        fputs(M[idx].body[i], out);
      continue;
    }
    if (toks >= 2) {
      idx = find_macro(t2);
      if (idx >= 0) {
        /* prefix label (t1) to first line of macro body, then rest normally */
        if (M[idx].n > 0) {
          /* print label + tab + first body line (trim leading spaces on body
           * first line) */
          char *b = M[idx].body[0];
          while (*b && (*b == ' ' || *b == '\t'))
            b++;
          fprintf(out, "%-8s\t%s", t1, b); /* body already has newline */
          for (int i = 1; i < M[idx].n; i++)
            fputs(M[idx].body[i], out);
        }
        continue;
      }
    }

    /* Not a macro def or call — copy line unchanged */
    fputs(line, out);
  }

  fclose(in);
  fclose(out);
  printf("Done. See macro-output.txt\n");
  return 0;
}
