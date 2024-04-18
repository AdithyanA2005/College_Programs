#include <stdio.h>
int main() {
  int n, temp, sum = 0;
  printf("Enter value for n: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++)  {
    printf("Enter element %d: ", i + 1);
    scanf("%d", &temp);  
    sum += temp;
  }

  printf("\nThe sum is: %d", sum);
}
