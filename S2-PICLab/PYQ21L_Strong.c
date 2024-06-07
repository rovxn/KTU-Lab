#include <stdio.h>

// Function to calculate factorial
int factorial(int n) {
    int fact = 1;
    for(int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Function to check if a number is strong
int isStrong(int num) {
    int originalNum = num;
    int sum = 0;

    while(num > 0) {
        int digit = num % 10;
        sum += factorial(digit);
        num /= 10;
    }

    return (originalNum == sum);
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if(isStrong(num)) {
        printf("%d is a strong number.\n", num);
    } else {
        printf("%d is not a strong number.\n", num);
    }

    return 0;
}