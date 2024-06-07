#include <stdio.h>

int main() {
    FILE *file;
    char path[100];
    char ch;
    int linesCount = 0;

    printf("Enter the file path: ");
    scanf("%s", path);

    // Open the file
    file = fopen(path, "r");

    // Check if file exists
    if (file == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }

    // Read contents from file
    while ((ch = fgetc(file)) != EOF) {
        // Check for new line
        if (ch == '\n') {
            linesCount++;
        }
    }

    // Close the file
    fclose(file);

    printf("Number of lines: %d\n", linesCount);

    return 0;
}