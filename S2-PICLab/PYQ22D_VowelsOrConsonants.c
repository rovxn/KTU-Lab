#include <stdio.h>
#include <ctype.h>

int main() {
    char c;

    printf("Enter a character: ");
    scanf("%c", &c);

    c = tolower(c); // convert to lowercase for simplicity

    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        printf("%c is a vowel.\n", c);
    } else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        printf("%c is a consonant.\n", c);
    } else {
        printf("%c is not an alphabetic character.\n", c);
    }

    return 0;
}