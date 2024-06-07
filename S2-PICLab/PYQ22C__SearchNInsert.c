#include <stdio.h>

void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, num, i, found = 0;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n+1]; // +1 to accommodate possible insertion
    printf("Enter the elements of the array: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number to search: ");
    scanf("%d", &num);

    for(i = 0; i < n; i++) {
        if(arr[i] == num) {
            printf("Number found at position %d\n", i+1);
            found = 1;
            break;
        }
    }

    if(!found) {
        arr[n] = num;
        printf("Number not found. Inserted at position %d\n", n+1);
    }

    printf("Final array: ");
    printArray(arr, n + !found); // if number was not found, size is n+1

    return 0;
}