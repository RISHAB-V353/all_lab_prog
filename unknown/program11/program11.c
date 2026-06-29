//Add Two Integer Arrays Element-wise Using Pointers

#include <stdio.h>

int main()
{
    int n,i;

    printf("Enter size of arrays: ");
    scanf("%d",&n);

    int a[n],b[n],sum[n];

    printf("Enter first array:\n");

    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    printf("Enter second array:\n");

    for(i=0;i<n;i++)
        scanf("%d",&b[i]);

    int *p=a,*q=b,*r=sum;

    for(i=0;i<n;i++)
    {
        *(r+i)=*(p+i)+*(q+i);
    }

    printf("Sum Array:\n");

    for(i=0;i<n;i++)
        printf("%d ",sum[i]);

    return 0;
}