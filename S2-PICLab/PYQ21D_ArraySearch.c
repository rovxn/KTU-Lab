#include <stdio.h>

// Function to perform linear search
int linearSearch(int* arr, int size, int target) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == target) {
            return i; // return the index of the target
        }
    }
    return -1; // return -1 if the target is not found
}

int main() {
    int n, target;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number to search: ");
    scanf("%d", &target);

    int result = linearSearch(arr, n, target);

    if(result != -1) {
        printf("Number found at index: %d\n", result);
    } else {
        printf("Number not found in the array.\n");
    }

    return 0;
}