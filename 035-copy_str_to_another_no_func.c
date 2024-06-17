#include <stdio.h>

int main() {
    char source[100], destination[100];
    int i = 0;

    printf("Enter a string: ");
    scanf("%s", source);

    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }

    destination[i] = '\0';
    printf("Copied string: %s\n", destination);

    return 0;
}
