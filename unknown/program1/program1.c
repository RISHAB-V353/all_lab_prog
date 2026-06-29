//Swapping Maximum Scores Between Two Teams Using Arrays

#include <stdio.h>

int main() {
    int n, i;
    printf("Enter number of players: ");
    scanf("%d", &n);

    int team1[n], team2[n];

    printf("Enter Team 1 scores:\n");
    for(i=0;i<n;i++)
        scanf("%d",&team1[i]);

    printf("Enter Team 2 scores:\n");
    for(i=0;i<n;i++)
        scanf("%d",&team2[i]);

    int max1=0,max2=0;

    for(i=1;i<n;i++)
        if(team1[i]>team1[max1])
            max1=i;

    for(i=1;i<n;i++)
        if(team2[i]>team2[max2])
            max2=i;

    int temp=team1[max1];
    team1[max1]=team2[max2];
    team2[max2]=temp;

    printf("\nTeam 1:\n");
    for(i=0;i<n;i++)
        printf("%d ",team1[i]);

    printf("\nTeam 2:\n");
    for(i=0;i<n;i++)
        printf("%d ",team2[i]);

    return 0;
}