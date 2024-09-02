#include <stdio.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

int main() {
    int choice, temp;

    printf("STACK\n-----\n");
    printf("1 - Push\n2 - Pop\n3 - Display\n");

  while (1) {
    printf("\nEnter Choice:");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter data: ");
        scanf("%d", &temp);

        if (top == MAX_SIZE - 1) {
          printf("Stack Overflow\n");
          continue;
        }

        stack[++top] = temp;
        printf("Pushed element: %d\n", temp);
        break;
      case 2:
        if (top == -1) {
          printf("Stack Underflow\n");
          continue;
        }

        temp = stack[top--];
        printf("Popped element: %d\n", temp);
        break;
    case 3:
      for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
      printf("\n");
      break;
    }
  }
    return 0;
}
