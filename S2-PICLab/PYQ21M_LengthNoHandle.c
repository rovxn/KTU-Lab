#include <stdio.h>

int stringLength(char str[]) {
    int length = 0;

    // Count the number of characters until the null terminator
    while (str[length] != '\0') {
        length++;
    }

    return length;
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); // read string

    str[strlen(str) - 1] = '\0'; // remove newline character

    printf("Length of the string is: %d\n", stringLength(str));

    return 0;
}