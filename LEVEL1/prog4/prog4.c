#include<stdio.h>
#include<string.h>

typedef struct{
    int fnumber, seats;
    char name[50];
}Flights;

void input(Flights flight[], int n);
int find_flight(Flights flight[], int n, char search[], int result[]);
void display(Flights flight[], int count, int result[]);

int main(){
    int n;
    char search[50];
    printf("Enter the number of Flights: ");
    scanf("%d", &n);

    int result[n];

    if(n<1){
        printf("Invalid number of flights!");
        return 0;
    }

    Flights flight[n];

    input(flight, n);

    printf("Enter your destination: ");
    scanf("%s", search);

    int count = find_flight(flight, n, search, result);

    display(flight, count, result);

    return 0;
}

void input(Flights flight[], int n){
    printf("Enter flight details: \n");
    for(int i=0; i<n; i++){
        printf("Enter flight number of flight%d: ", i+1);
        scanf("%d", &flight[i].fnumber);
        printf("Enter name of flight%d: ", i+1);
        scanf("%s", flight[i].name);
        printf("Enter number of seats in flight%d: ", i+1);
        scanf("%d", &flight[i].seats);
        printf("\n");
    }
}

int find_flight(Flights flight[], int n, char search[], int result[]){
    int count = 0;
    for(int i=0; i<n; i++){
        if(strcmp(flight[i].name, search)==0){
            result[count] = i;
            count++;
        }
    }
    return count;
}

void display(Flights flight[], int count, int result[]){
    if(count == 0){
        printf("Flights unavailable!");
    }
    else{
        if(count == 1){
            printf("%d flight available!\n", count);
        }
        else{
            printf("%d flights available!\n", count);
        }
        
        for(int i=0; i<count; i++){
            printf("Flight number: %d\n", flight[result[i]].fnumber);
        }
    }
    
}
