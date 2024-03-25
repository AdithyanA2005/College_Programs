#include <stdio.h>

int main() {
  int num, flag;

  printf("Enter number: ");
  scanf("%d", &num);

  for (int i = 0; i <= num; i++) {
    flag = 1;

    for (int j = 2; j < i; j++) {
      if (i % j == 0) flag = 0;
    }

    if (flag == 1)
      printf("%d ", i);
  }
}
