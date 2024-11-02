#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char input[20];
int temp = 1;
char priority[4] = {'-', '+', '*', '/'};
int evaluate();
void main()
{
    printf("Enter the input expression: ");
    scanf("%s", input);
    while (input[1] != -1)
    {
        int i = 0;
        int min = -1;
        int p = -1;
        while (i < strlen(input))
        {
            for (int j = 0; j < 4; j++)
            {
                if (input[i] == priority[j])
                {
                    if (j > p)
                    {
                        p = j;
                        min = i;
                    }
                }
            }
            i++;
        }
        printf("t%d = ", temp);
        if ((int)input[min - 1] >= 49 && (int)input[min - 1] <= 57)
        {
            printf(" t%c ", input[min - 1]);
        }
        else
            printf(" %c ", input[min - 1]);
        printf(" %c ", input[min]);
        if ((int)input[min + 1] >= 49 && (int)input[min + 1] <= 57)
        {
            printf(" t%c ", input[min + 1]);
        }
        else
            printf(" %c ", input[min + 1]);
        input[min - 1] = (char)49 + temp - 1;
        for (int j = min; j < strlen(input) - 1; j++)
        {
            input[j] = input[j + 2];
        }
        evaluate();
        temp++;
        if (strlen(input) == 1)
        {
            break;
        }
    }
}
int evaluate()
{
    printf("\t\t\t");
    for (int i = 0; i < strlen(input); i++)
    {
        printf("%c", input[i]);
    }
    printf("\n");
}