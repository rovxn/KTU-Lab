#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_STATEMENTS 10
#define MAX_LENGTH 10
struct st
{
    char op[2];
    char op1[MAX_LENGTH];
    char op2[MAX_LENGTH];
    char res[MAX_LENGTH];
    int is_constant;
    int value;
} ans[MAX_STATEMENTS];
int n;
void propagate(int i, int value)
{
    for (int j = i + 1; j < n; j++)
    {
        if (strcmp(ans[j].op1, ans[i].res) == 0)
        {
            sprintf(ans[j].op1, "%d", value);
        }
        if (strcmp(ans[j].op2, ans[i].res) == 0)
        {
            sprintf(ans[j].op2, "%d", value);
        }
    }
}
void checkConstants()
{
    for (int i = 0; i < n; i++)
    {
        int result;
        if (strcmp(ans[i].op, "=") == 0)
        {
            if (isdigit(ans[i].op1[0]))
            {
                int value = atoi(ans[i].op1);
                propagate(i, value);
                ans[i].is_constant = 1;
                ans[i].value = value;
            }
        }
        else if (ans[i].is_constant == 1)
        {
            if (isdigit(ans[i].op1[0]) && isdigit(ans[i].op2[0]))
            {
                int a = (isdigit(ans[i].op1[0])) ? atoi(ans[i].op1) : ans[i].value;
                int b = atoi(ans[i].op2);
                if (strcmp(ans[i].op, "+") == 0)
                {
                    result = a + b;
                }
                else if (strcmp(ans[i].op, "-") == 0)
                {
                    result = a - b;
                }
                else if (strcmp(ans[i].op, "*") == 0)
                {
                    result = a * b;
                }
                else if (strcmp(ans[i].op, "/") == 0 && b != 0)
                {
                    result = a / b;
                }
                ans[i].value = result;
                propagate(i, result);
                sprintf(ans[i].op1, "%d", result);
                ans[i].is_constant = 1;
            }
        }
    }
}
int main()
{
    printf("Enter the number of statements: ");
    scanf("%d", &n);
    char eq[2];
    printf("Enter the Quadform [Note: if only one operand, give '_' for other operand]:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%s %s %s %s %s", ans[i].res, eq, ans[i].op1, ans[i].op, ans[i].op2);
        if (strcmp(ans[i].op, "_") == 0)
        {
            strcpy(ans[i].op, "=");
        }
        ans[i].is_constant = 0;
    }
    checkConstants();
    printf("Optimized code:\n");
    for (int i = 0; i < n; i++)
    {
        if (ans[i].is_constant == 0)
        {
            printf("%s = %s %s %s\n", ans[i].res, ans[i].op1, ans[i].op, (strcmp(ans[i].op2, "0") == 0) ? "" : ans[i].op2);
        }
        else if (strcmp(ans[i].op, "=") == 0)
        {
            printf("%s = %s\n", ans[i].res, ans[i].op1);
        }
        else
        {
            printf("%s = %d\n", ans[i].res, ans[i].value);
        }
    }
    return 0;
}