#include <stdio.h>

int main() {
  int num, isPrime = 1; // Default set it as a prime number
  printf("Enter number: ");
  scanf("%d", &num);

  if (num <= 2) {
    printf("This is not a prime number, because its less than 2");
  } else {
    for (int i = 2; i < num/2; i++) {
      if (num % i == 0) isPrime = 0;
    }

    if (isPrime == 1) printf("Its a prime number");
    else printf("Its not a prime number");
  }
}
