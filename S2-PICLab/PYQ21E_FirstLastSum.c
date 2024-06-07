#include <stdio.h>

// Function to find the sum of first and last digit
int sumOfFirstAndLastDigit(int num) {
    int lastDigit = num % 10; // get the last digit

    // get the first digit
    int firstDigit = num;
    while(firstDigit >= 10) {
        firstDigit /= 10;
    }

    return firstDigit + lastDigit;
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    int sum = sumOfFirstAndLastDigit(num);

    printf("Sum of first and last digit: %d\n", sum);

    return 0;
}