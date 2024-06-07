#include <stdio.h>

int isPalindrome(char str[]) {
    int start, end, length = 0;

    // Find the length of the string
    while (str[length] != '\0') {
        length++;
    }

    // Compare characters from the start and end of the string
    start = 0;
    end = length - 1;
    while (start < end) {
        if (str[start] != str[end]) {
            return 0; // Not a palindrome
        }
        start++;
        end--;
    }

    return 1; // Palindrome
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); // read string

    str[strlen(str) - 1] = '\0'; // remove newline character

    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}