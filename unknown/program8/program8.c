//Seat Number Sorting System

#include <stdio.h>

int main()
{
    int n,i,j,temp;

    printf("Enter number of students: ");
    scanf("%d",&n);

    int seat[n];

    printf("Enter seat numbers:\n");

    for(i=0;i<n;i++)
        scanf("%d",&seat[i]);

    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(seat[j]>seat[j+1])
            {
                temp=seat[j];
                seat[j]=seat[j+1];
                seat[j+1]=temp;
            }
        }
    }

    printf("Sorted Seat Numbers:\n");

    for(i=0;i<n;i++)
        printf("%d ",seat[i]);

    return 0;
}