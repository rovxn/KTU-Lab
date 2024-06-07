#include <stdio.h>
#include <string.h>

void reverse(char* str) {
    int length, i;
    char *begin_ptr, *end_ptr, ch;

    // Get the length of the string
    length = strlen(str);

    // Set the begin_ptr and end_ptr
    // initially to start of string
    begin_ptr = str;
    end_ptr = str;

    // Move the end_ptr to the last character
    for (i = 0; i < length - 1; i++)
        end_ptr++;

    // Swap the char from start and end
    // index using begin_ptr and end_ptr
    for (i = 0; i < length / 2; i++) {        
        ch = *end_ptr;
        *end_ptr = *begin_ptr;
        *begin_ptr = ch;

        // update pointers positions
        begin_ptr++;
        end_ptr--;
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); // read string

    str[strlen(str) - 1] = '\0'; // remove newline character

    reverse(str); // reverse the string

    printf("Reverse of the string: %s\n", str);

    return 0;
}