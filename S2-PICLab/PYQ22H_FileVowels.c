#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fp;
    char ch;

    fp = fopen("file.txt", "r+"); // open the file in read and write mode

    if(fp == NULL) {
        printf("File cannot be opened.\n");
        return 1;
    }

    while((ch = fgetc(fp)) != EOF) { // read the file character by character
        ch = tolower(ch);
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            fseek(fp, -1, SEEK_CUR); // move the file pointer one step back
            fputc('x', fp); // replace the vowel with 'x'
        }
    }

    fclose(fp); // close the file

    printf("Vowels replaced successfully.\n");

    return 0;
}