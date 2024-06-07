#include <stdio.h>

#define SIZE 100 // Maximum size of the name

// Define the structure
typedef struct {
    char name[SIZE];
    float price;
    int quantity;
    float totalAmount;
} Item;

// Function to read data
void readData(Item *item) {
    printf("Enter name: ");
    scanf("%s", item->name);

    printf("Enter price: ");
    scanf("%f", &(item->price));

    printf("Enter quantity: ");
    scanf("%d", &(item->quantity));

    // Calculate total amount
    item->totalAmount = item->price * item->quantity;
}

// Function to print data
void printData(Item item) {
    printf("Name: %s\n", item.name);
    printf("Price: %.2f\n", item.price);
    printf("Quantity: %d\n", item.quantity);
    printf("Total Amount: %.2f\n", item.totalAmount);
}

int main() {
    Item item;

    readData(&item);
    printData(item);

    return 0;
}