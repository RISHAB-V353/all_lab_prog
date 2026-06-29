//C Program to Manage the Ages of a Group of People Using Dynamic Memory Allocation

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i;

    printf("Enter number of people: ");
    scanf("%d",&n);

    int *age=(int*)malloc(n*sizeof(int));

    printf("Enter ages:\n");

    for(i=0;i<n;i++)
        scanf("%d",&age[i]);

    printf("\nAges are:\n");

    for(i=0;i<n;i++)
        printf("%d ",age[i]);

    free(age);

    return 0;
}