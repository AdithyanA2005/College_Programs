#include <stdbool.h>
#include <stdio.h>

int findLRU(int lastUsed[], int framesCount) {
  int min = lastUsed[0], pos = 0;
  for (int i = 1; i < framesCount; i++) {
    if (lastUsed[i] < min) {
      min = lastUsed[i];
      pos = i;
    }
  }
  return pos;
}

int main() {
  int framesCount, n;
  printf("Enter number of frames: ");
  scanf("%d", &framesCount);

  printf("Enter number of pages: ");
  scanf("%d", &n);

  int pages[n];
  printf("Enter page reference string: ");
  for (int i = 0; i < n; i++)
    scanf("%d", &pages[i]);

  int frames[framesCount], lastUsed[framesCount];
  for (int i = 0; i < framesCount; i++) {
    frames[i] = -1;
    lastUsed[i] = -1;
  }

  int time = 0, faults = 0;

  for (int i = 0; i < n; i++) {
    int page = pages[i];
    bool hit = false;

    // Check for hit
    for (int j = 0; j < framesCount; j++) {
      if (frames[j] == page) {
        hit = true;
        lastUsed[j] = time;
        break;
      }
    }

    // On miss
    if (!hit) {
      int pos = -1;
      // Find empty frame
      for (int j = 0; j < framesCount; j++) {
        if (frames[j] == -1) {
          pos = j;
          break;
        }
      }
      // If no empty, pick least recently used
      if (pos == -1)
        pos = findLRU(lastUsed, framesCount);

      frames[pos] = page;
      lastUsed[pos] = time;
      faults++;
    }

    // Print frames after each reference
    printf("Page %d -> ", page);
    for (int j = 0; j < framesCount; j++) {
      if (frames[j] == -1)
        printf("- ");
      else
        printf("%d ", frames[j]);
    }
    printf("\n");

    time++;
  }

  printf("\nTotal Page Faults: %d\n", faults);
  return 0;
}
