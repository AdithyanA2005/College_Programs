#include <stdio.h>

int main() {
  int frames, pages[30], frame[10], count = 0, pageFaults = 0;
  int n, i, j, flag, k;

  printf("Enter number of frames: ");
  scanf("%d", &frames);

  printf("Enter number of pages: ");
  scanf("%d", &n);

  printf("Enter page reference string: ");
  for (i = 0; i < n; i++)
    scanf("%d", &pages[i]);

  for (i = 0; i < frames; i++)
    frame[i] = -1;

  for (i = 0; i < n; i++) {
    flag = 0;
    for (j = 0; j < frames; j++) {
      if (frame[j] == pages[i]) {
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      frame[count] = pages[i];
      count = (count + 1) % frames;
      pageFaults++;
    }
    printf("Page %d -> ", pages[i]);
    for (k = 0; k < frames; k++)
      if (frame[k] != -1)
        printf("%d ", frame[k]);
      else
        printf("- ");
    printf("\n");
  }
  printf("Total Page Faults = %d\n", pageFaults);
  return 0;
}
