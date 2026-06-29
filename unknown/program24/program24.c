//C Program to Manage the Ages of a Group of People Using Dynamic Memory Allocation (Alternative Version)

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    float avg = 0;

    printf("Enter number of people: ");
    scanf("%d", &n);

    int *age = (int *)malloc(n * sizeof(int));

    if(age == NULL)
    {
        printf("Memory Allocation Failed");
        return 0;
    }

    printf("Enter ages:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &age[i]);
        avg += age[i];
    }

    avg /= n;

    printf("\nAverage Age = %.2f\n", avg);

    printf("Ages are:\n");

    for(i = 0; i < n; i++)
        printf("%d ", age[i]);

    free(age);

    return 0;
}