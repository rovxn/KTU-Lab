#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
void main()
{
    int n;
    char mat[100][100];
    char Ins[10][10] = {"ADD", "SUB", "MUL", "DIV", "MOV"};
    int ind = 0;
    printf("Enter number of productions: ");
    scanf("%d", &n);
    printf("Enter The three address codes: \n---\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%s", mat[i]);
    }
    printf("---\n\n8086 Instructions:\n---\n");
    for (int i = 0; i < n; i++)
    {
        int tar;
        if (strlen(mat[i]) > 3)
        {
            switch (mat[i][3])
            {
            case '+':
            {
                ind = 0;
                if (isdigit(mat[i][2]) && isdigit(mat[i][4]))
                {
                    tar = (mat[i][2] - '0') + (mat[i][4] - '0');
                }
                break;
            }
            case '-':
            {
                ind = 1;
                if (isdigit(mat[i][2]) && isdigit(mat[i][4]))
                    tar = (mat[i][2] - '0') - (mat[i][4] - '0');
                break;
            }
            case '*':
            {
                ind = 2;
                if (isdigit(mat[i][2]) && isdigit(mat[i][4]))
                    tar = (mat[i][2] - '0') * (mat[i][4] - '0');
                break;
            }
            case '/':
            {
                ind = 3;
                if (isdigit(mat[i][2]) && isdigit(mat[i][4]))
                    tar = (mat[i][2] - '0') / (mat[i][4] - '0');
                break;
            }
            case '=':
            {
                ind = 4;
                break;
            }
            }
            printf("%s %c,%c \n", Ins[ind], mat[i][2], mat[i][4]);
            if (isdigit(mat[i][2]) && isdigit(mat[i][4]))
                printf("MOV %c,%d \n", mat[i][0], tar);
            else
                printf("MOV %c,%c \n", mat[i][0], mat[i][2]);
        }
        else
        {
            printf("MOV %c,%c\n", mat[i][0], mat[i][2]);
        }
    }
    printf("---\n");
}