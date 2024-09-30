#include<stdio.h>
#include<ctype.h>

int stack[20];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

void main() {
    char exp[20];
    int n1, n2, n3, num;
    printf("Enter the postfix expression :: ");
    scanf("%s", exp);
    int i = 0;

    while (exp[i] != '\0') {
        if (isdigit(exp[i])) {
            num = exp[i] - '0';
            push(num);
        }
        else {
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
            }
            push(n3);
        }
        i++;
    }
    
    printf("\nThe result of postfix expression %s = %d\n\n", exp, pop());
}