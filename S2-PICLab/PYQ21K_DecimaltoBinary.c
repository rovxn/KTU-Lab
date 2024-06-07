#include <stdio.h>

void decimalToBinary(int n) {
    int binaryNum[32];
    int i = 0;

    // convert decimal to binary
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // print binary number
    printf("Binary of given number is: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binaryNum[j]);
    }
}

int main() {
    int num;

    printf("Enter a decimal number: ");
    scanf("%d", &num);

    decimalToBinary(num); // convert decimal to binary

    return 0;
}