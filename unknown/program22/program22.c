//Horner's Method

#include <stdio.h>

int main()
{
    int n, i, x;

    printf("Enter degree of polynomial: ");
    scanf("%d", &n);

    int coeff[n + 1];

    printf("Enter coefficients:\n");

    for(i = 0; i <= n; i++)
        scanf("%d", &coeff[i]);

    printf("Enter value of x: ");
    scanf("%d", &x);

    int result = coeff[0];

    for(i = 1; i <= n; i++)
        result = result * x + coeff[i];

    printf("Polynomial Value = %d", result);

    return 0;
}