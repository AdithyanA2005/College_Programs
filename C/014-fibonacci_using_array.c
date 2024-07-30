#include <stdio.h>
int main() {
  int limit;
  printf("Enter the limit: ");
  scanf("%d", &limit);

  int series[limit];
  series[0] = 0;
  series[1] = 1;

  for (int i = 2; i < limit; i++) 
    series[i] = series[i-1] + series[i-2];

  printf("\nThe fibonacci series is:\n");
  for (int i = 0; i < limit; i++)
    printf("%d ", series[i]);

}
