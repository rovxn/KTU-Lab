#include <stdio.h>

#define SIZE 100 // Maximum size of the matrix

int main() {
    int m, n, matrix[SIZE][SIZE], transpose[SIZE][SIZE];

    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d%d", &m, &n);

    printf("Enter elements of the matrix:\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Finding the transpose of matrix
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    printf("\nTranspose of the matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}