#include <stdio.h>

int main() {
  int noOfSubjects;
  float sum, avg, percent;
  printf("Enter the number of subjects: ");
  scanf("%d", &noOfSubjects);

  float mark[noOfSubjects];
  printf("\nENTER MARKS OF SUBJECTS\n");
  for (int i = 0; i < noOfSubjects; i++) {
    printf("Enter mark of subject %d: ", i + 1);
    scanf("%f", &mark[i]);
  } 

  sum = 0;
  for (int i = 0; i < noOfSubjects; i++) 
    sum += mark[i];

  avg = sum / noOfSubjects;

  percent = (sum / (100 * noOfSubjects)) * 100;

  printf("\nThe Sum is %.2f", sum);
  printf("\nThe Average is %.2f", avg);
  printf("\nThe Percent is %.2f", percent);
}
