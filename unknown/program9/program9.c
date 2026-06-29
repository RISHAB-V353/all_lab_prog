//Search Book Index

#include <stdio.h>

int main()
{
    int n,i,key,found=0;

    printf("Enter number of books: ");
    scanf("%d",&n);

    int index[n];

    printf("Enter book indices:\n");

    for(i=0;i<n;i++)
        scanf("%d",&index[i]);

    printf("Enter book index to search: ");
    scanf("%d",&key);

    for(i=0;i<n;i++)
    {
        if(index[i]==key)
        {
            printf("Book found at position %d",i+1);
            found=1;
            break;
        }
    }

    if(!found)
        printf("Book not found.");

    return 0;
}