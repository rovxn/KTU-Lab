#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = x;
}

int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

int main() {
    char exp[MAX];
    int i, num, n1, n2, n3;

    printf("Enter the postfix expression: ");
    scanf("%s", exp);

    i = 0;
    while (exp[i] != '\0') {
        if (isdigit(exp[i])) {
            num = exp[i] - '0';
            push(num);
        } else {
            n1 = pop();
            n2 = pop();
            switch (exp[i]) {
                case '+':
                    n3 = n2 + n1;
                    break;
                case '-':
                    n3 = n2 - n1;
                    break;
                case '*':
                    n3 = n2 * n1;
                    break;
                case '/':
                    n3 = n2 / n1;
                    break;
                default:
                    printf("Invalid operator\n");
                    exit(1);
            }
            push(n3);
        }
        i++;
    }

    printf("\nThe result of postfix expression %s = %d\n\n", exp, pop());
    return 0;
}