//Delete Element from Given Position in an Array

#include <stdio.h>

int main()
{
    int n,i,pos;

    printf("Enter array size: ");
    scanf("%d",&n);

    int arr[n];

    printf("Enter elements:\n");

    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    printf("Enter position to delete: ");
    scanf("%d",&pos);

    if(pos<1 || pos>n)
    {
        printf("Invalid Position");
        return 0;
    }

    for(i=pos-1;i<n-1;i++)
        arr[i]=arr[i+1];

    n--;

    printf("Array after deletion:\n");

    for(i=0;i<n;i++)
        printf("%d ",arr[i]);

    return 0;
}