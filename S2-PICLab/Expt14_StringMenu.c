#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    int choice;

    printf("Enter first string: ");
    gets(str1);

    printf("Enter second string: ");
    gets(str2);

    do {
        printf("\nMenu:\n");
        printf("1. Length of strings\n");
        printf("2. Copy string\n");
        printf("3. Concatenate strings\n");
        printf("4. Compare strings\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Length of first string: %d\n", strlen(str1));
                printf("Length of second string: %d\n", strlen(str2));
                break;
            case 2:
                strcpy(str1, str2);
                printf("After copying, string: %s\n", str1);
                break;
            case 3:
                strcat(str1, str2);
                printf("After concatenation, string: %s\n", str1);
                break;
            case 4:
                if(strcmp(str1, str2) == 0)
                    printf("Strings are equal.\n");
                else
                    printf("Strings are not equal.\n");
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice != 5);

    return 0;
}