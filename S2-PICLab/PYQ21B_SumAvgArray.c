#include <stdio.h>

// Function to calculate sum of array
int sumOfArray(int* arr, int size) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// Function to calculate average of array
float averageOfArray(int* arr, int size) {
    int sum = sumOfArray(arr, size);
    return (float)sum / size;
}

int main() {
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Sum of array: %d\n", sumOfArray(arr, n));
    printf("Average of array: %.2f\n", averageOfArray(arr, n));

    return 0;
}