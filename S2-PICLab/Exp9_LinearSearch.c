#include <stdio.h>

int linearSearch(int arr[], int size, int element){
    for(int i = 0; i < size; i++){
        if(arr[i] == element){
            return i;
        }
    }
    return -1;
}

int main() {
    int size, element, searchIndex;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter elements of the array: ");
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &element);

    searchIndex = linearSearch(arr, size, element);

    if(searchIndex != -1){
        printf("Element found at index: %d\n", searchIndex);
    } else {
        printf("Element not found in the array.\n");
    }

    return 0;
}