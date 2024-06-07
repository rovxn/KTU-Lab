#include <stdio.h>

int main() {
    FILE *sourceFile, *targetFile;
    char ch;

    sourceFile = fopen("source.txt", "r");
    if(sourceFile == NULL) {
        printf("Unable to open source file.\n");
        return 1;
    }

    targetFile = fopen("target.txt", "w");
    if(targetFile == NULL) {
        fclose(sourceFile);
        printf("Unable to open target file.\n");
        return 1;
    }

    while((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, targetFile); // Writing to target file
    }

    printf("File copied successfully.\n");

    // Closing the files
    fclose(sourceFile);
    fclose(targetFile);

    return 0;
}