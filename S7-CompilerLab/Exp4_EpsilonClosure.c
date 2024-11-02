#include <stdio.h>
#include <stdlib.h>
int findvalue(char c)
{
    char s[2];
    int d, i;
    s[0] = c;
    s[1] = '\0';
    d = atoi(s);
    return (d);
}
void main()
{
    int noalpha, nostate, notrans, eclos[10][20], i, j, k, d;
    char alpha[5], trans[30][3], c;
    printf("Enter the number of alphabets?\n");
    scanf("%d", &noalpha);
    printf("\nEnter alphabets?\n");
    for (i = 0; i < noalpha; i++)
    {
        getchar();
        alpha[i] = getchar();
    }
    printf("\nEnter the number of states?\n");
    scanf("%d", &nostate);
    printf("\nEnter no of transition?\n");
    scanf("%d", &notrans);
    printf("\nEnter transition?\n");
    for (i = 0; i < notrans; i++)
    {
        getchar();
        trans[i][0] = getchar();
        getchar();
        trans[i][1] = getchar();
        getchar();
        trans[i][2] = getchar();
    }
    printf("\n");
    printf("e-closure of states\n");
    for (i = 1; i <= nostate; i++)
    {
        for (k = 0; k < 20; k++)
        {
            eclos[i][k] = 0;
        }
    }
    for (i = 1; i <= nostate; i++)
    {
        c = 0;
        eclos[i][c] = i;
        c++;
        k = i;
        for (j = 0; j < notrans; j++)
        {
            d = findvalue(trans[j][0]);
            if (k == d && trans[j][1] == 'e')
            {
                eclos[i][c] = findvalue(trans[j][2]);
                k = eclos[i][c];
                c++;
            }
        }
    }
    for (i = 1; i <= nostate; i++)
    {
        printf("e-closure of q%d -{", i);
        for (j = 0; eclos[i][j] != 0; j++)
        {
            printf("q%d,", eclos[i][j]);
        }
        printf("}\n");
    }
}
