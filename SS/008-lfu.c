#include <stdbool.h>
#include <stdio.h>

int findLFU(int freq[], int frames[], int framesCount) {
  int minFreq = freq[0], pos = 0;
  for (int i = 1; i < framesCount; i++) {
    if (freq[i] < minFreq) {
      minFreq = freq[i];
      pos = i;
    }
  }
  return pos;
}

int main() {
  int framesCount, n;
  printf("Enter number of frames: ");
  scanf("%d", &framesCount);

  printf("Enter number of pages in reference string: ");
  scanf("%d", &n);

  int pages[n];
  printf("Enter page reference string: ");
  for (int i = 0; i < n; i++)
    scanf("%d", &pages[i]);

  int frames[framesCount], freq[framesCount];
  for (int i = 0; i < framesCount; i++) {
    frames[i] = -1;
    freq[i] = 0;
  }

  int faults = 0;

  printf("\nRef\tFrames\n");
  for (int i = 0; i < n; i++) {
    int page = pages[i];
    bool hit = false;

    // Check for hit
    for (int j = 0; j < framesCount; j++) {
      if (frames[j] == page) {
        hit = true;
        freq[j]++; // increase frequency
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
      // If no empty, replace LFU
      if (pos == -1)
        pos = findLFU(freq, frames, framesCount);

      frames[pos] = page;
      freq[pos] = 1;
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
  }

  printf("\nTotal Page Faults: %d\n", faults);
  return 0;
}
