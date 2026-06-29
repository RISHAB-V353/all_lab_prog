//Lowest Inventory Check

#include <stdio.h>

int main()
{
    int n, i, minIndex = 0;

    printf("Enter number of products: ");
    scanf("%d", &n);

    int stock[n];

    printf("Enter stock quantity:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &stock[i]);

    for(i = 1; i < n; i++)
    {
        if(stock[i] < stock[minIndex])
            minIndex = i;
    }

    printf("Lowest Inventory = %d", stock[minIndex]);

    return 0;
}