#include <stdio.h>

void printArrayInReverse(int* arr, int size) {
    int* arrEnd = (arr + size - 1); // Pointer to the end of the array

    for(int* ptr = arrEnd; ptr >= arr; ptr--) {
        printf("%d ", *ptr);
    }
    printf("\n");
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

    printf("Array in reverse order: ");
    printArrayInReverse(arr, n);

    return 0;
}