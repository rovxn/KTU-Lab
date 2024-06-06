#include <stdio.h>

int main() {
    int num;
    long factorial = 1;

    printf("Enter an integer: ");
    scanf("%d", &num);

    // show error if the user enters a negative integer
    if (num < 0)
        printf("Error! Factorial of a negative number doesn't exist.\n");
    else {
        for(int i = 1; i <= num; ++i) {
            factorial *= i;
        }
        printf("Factorial of %d = %llu\n", num, factorial);
    }

    return 0;
}