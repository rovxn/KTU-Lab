#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int n, m, i, j, k, available[10], allocation[10][10], max[10][10], need[10][10], work[10], finish[10], safe[10], count = 0;

void input();
void display();
void bankers();

int main()
{
    input();
    display();
    bankers();
    return 0;
}

void input()
{
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);
    printf("Enter the available resources: ");
    for (i = 0; i < m; i++)
        scanf("%d", &available[i]);
    printf("Enter the allocation matrix: ");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &allocation[i][j]);
    printf("Enter the max matrix: ");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - allocation[i][j];
}

void display()
{
    printf("Allocation matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf("%d ", allocation[i][j]);
        printf("\n");
    }
    printf("Max matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf("%d ", max[i][j]);
        printf("\n");
    }
    printf("Need matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf("%d ", need[i][j]);
        printf("\n");
    }
}

void bankers()
{
    int flag = 0;
    for (i = 0; i < n; i++)
        finish[i] = 0;
    for (i = 0; i < m; i++)
        work[i] = available[i];
    while (count < n)
    {
        for (i = 0; i < n; i++)
        {
            if (finish[i] == 0)
            {
                flag = 0;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    safe[count++] = i;
                    for (k = 0; k < m; k++)
                        work[k] += allocation[i][k];
                    finish[i] = 1;
                }
            }
        }
    }
    printf("Safe sequence: ");
    for (i = 0; i < n; i++)
        printf("%d ", safe[i]);
    printf("\n");
}