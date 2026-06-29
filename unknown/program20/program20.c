//Merge Two Arrays into Third Array

#include <stdio.h>

int main()
{
    int n1, n2, i;

    printf("Enter size of first array: ");
    scanf("%d", &n1);

    int a[n1];

    printf("Enter first array elements:\n");
    for(i = 0; i < n1; i++)
        scanf("%d", &a[i]);

    printf("Enter size of second array: ");
    scanf("%d", &n2);

    int b[n2];

    printf("Enter second array elements:\n");
    for(i = 0; i < n2; i++)
        scanf("%d", &b[i]);

    int c[n1 + n2];

    for(i = 0; i < n1; i++)
        c[i] = a[i];

    for(i = 0; i < n2; i++)
        c[n1 + i] = b[i];

    printf("Merged Array:\n");

    for(i = 0; i < n1 + n2; i++)
        printf("%d ", c[i]);

    return 0;
}