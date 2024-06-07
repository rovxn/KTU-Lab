#include <stdio.h>
#include <ctype.h>

// Function to count vowels and consonants
void countVowelsAndConsonants(char* str, int* vowels, int* consonants) {
    int v = 0;
    int c = 0;

    for(int i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]);
        if(ch >= 'a' && ch <= 'z') {
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                v++;
            } else {
                c++;
            }
        }
    }

    *vowels = v;
    *consonants = c;
}

int main() {
    char str[100];
    int vowels, consonants;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); // read string

    countVowelsAndConsonants(str, &vowels, &consonants);

    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);

    return 0;
}