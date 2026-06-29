//Student Marks Analysis

#include <stdio.h>

int main()
{
    int n,i;
    float sum=0,avg;
    int highest,lowest;

    printf("Enter number of students: ");
    scanf("%d",&n);

    int marks[n];

    printf("Enter marks:\n");

    for(i=0;i<n;i++)
        scanf("%d",&marks[i]);

    highest=lowest=marks[0];

    for(i=0;i<n;i++)
    {
        sum+=marks[i];

        if(marks[i]>highest)
            highest=marks[i];

        if(marks[i]<lowest)
            lowest=marks[i];
    }

    avg=sum/n;

    printf("Average = %.2f\n",avg);
    printf("Highest = %d\n",highest);
    printf("Lowest = %d\n",lowest);

    return 0;
}