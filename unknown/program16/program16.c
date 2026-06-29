//Add Two Arrays Using Dynamic Memory Allocation

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;

    printf("Enter size of arrays: ");
    scanf("%d", &n);

    int *a = (int*)malloc(n * sizeof(int));
    int *b = (int*)malloc(n * sizeof(int));
    int *sum = (int*)malloc(n * sizeof(int));

    printf("Enter first array:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter second array:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &b[i]);

    for(i = 0; i < n; i++)
        sum[i] = a[i] + b[i];

    printf("Sum Array:\n");
    for(i = 0; i < n; i++)
        printf("%d ", sum[i]);

    free(a);
    free(b);
    free(sum);

    return 0;
}