//Product Search Using Array of Structures

#include <stdio.h>
#include <string.h>

struct Product
{
    int id;
    char name[50];
    float price;
};

int main()
{
    int n,i,found=0;
    char search[50];

    printf("Enter number of products: ");
    scanf("%d",&n);

    struct Product p[n];

    for(i=0;i<n;i++)
    {
        printf("\nProduct %d\n",i+1);

        printf("ID: ");
        scanf("%d",&p[i].id);

        printf("Name: ");
        scanf(" %[^\n]",p[i].name);

        printf("Price: ");
        scanf("%f",&p[i].price);
    }

    printf("\nEnter product name to search: ");
    scanf(" %[^\n]",search);

    for(i=0;i<n;i++)
    {
        if(strcmp(search,p[i].name)==0)
        {
            printf("\nProduct Found\n");
            printf("ID : %d\n",p[i].id);
            printf("Name : %s\n",p[i].name);
            printf("Price : %.2f\n",p[i].price);
            found=1;
            break;
        }
    }

    if(!found)
        printf("Product not found.");

    return 0;
}