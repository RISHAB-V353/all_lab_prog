//Reverse Two Integer Arrays Separately

#include <stdio.h>

void reverse(int arr[],int n)
{
    int i,temp;

    for(i=0;i<n/2;i++)
    {
        temp=arr[i];
        arr[i]=arr[n-i-1];
        arr[n-i-1]=temp;
    }
}

int main()
{
    int n,i;

    printf("Enter size of arrays: ");
    scanf("%d",&n);

    int a[n],b[n];

    printf("Enter first array:\n");

    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    printf("Enter second array:\n");

    for(i=0;i<n;i++)
        scanf("%d",&b[i]);

    reverse(a,n);
    reverse(b,n);

    printf("\nReversed First Array:\n");

    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    printf("\nReversed Second Array:\n");

    for(i=0;i<n;i++)
        printf("%d ",b[i]);

    return 0;
}