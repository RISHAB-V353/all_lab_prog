//Compare Two Integer Arrays and Count Equal Elements at Same Index

#include <stdio.h>

int main()
{
    int n, i, count = 0;

    printf("Enter size of arrays: ");
    scanf("%d", &n);

    int a[n], b[n];

    printf("Enter first array:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter second array:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &b[i]);

    for(i = 0; i < n; i++)
    {
        if(a[i] == b[i])
            count++;
    }

    printf("Number of equal elements at same index = %d", count);

    return 0;
}