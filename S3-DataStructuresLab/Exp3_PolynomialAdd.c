// this is program to add two polynomials using arrays
#include <stdio.h>
#include <stdlib.h>
struct polynomial
{
    int coeff;
    int exp;
}p[10],q[10],r[10];
int n,m;
//array implementation method 1
void main(){
    int i=0,j=0,k=0;
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n);
    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &m);
    printf("Enter the coefficient and exponent of the first polynomial: ");
    read_poly(p,n);
    printf("Enter the coefficient and exponent of the second polynomial: ");
    read(q,m);
    add(p,q,r,n,m);
}
void read_poly(struct polynomial p[],int n){
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d%d", &p[i].coeff, &p[i].exp);
    }
}
void add(){
    int i=0,j=0,k=0;
    while (i < n && j < m)
    {
        if (p[i].exp == q[j].exp)
        {
            r[k].coeff = p[i].coeff + q[j].coeff;
            r[k].exp = p[i].exp;
            i++;
            j++;
            k++;
        }
        else if (p[i].exp > q[j].exp)
        {
            r[k].coeff = p[i].coeff;
            r[k].exp = p[i].exp;
            i++;
            k++;
        }
        else
        {
            r[k].coeff = q[j].coeff;
            r[k].exp = q[j].exp;
            j++;
            k++;
        }
    }
    while (i < n)
    {
        r[k].coeff = p[i].coeff;
        r[k].exp = p[i].exp;
        i++;
        k++;
    }
    while (j < m)
    {
        r[k].coeff = q[j].coeff;
        r[k].exp = q[j].exp;
        j++;
        k++;
    }
    printf("The sum of the two polynomials is: ");
    for (i = 0; i < k; i++)
    {
        printf("%dx^%d", r[i].coeff, r[i].exp);
        if (i != k - 1)
        {
            printf(" + ");
        }
    }
}

