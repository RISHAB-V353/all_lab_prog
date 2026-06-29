#include <stdio.h>  //program 4
#include <string.h>

/* Structure Definition */
typedef struct{
    int flightnumber;
    char destination[50];
    int seats;
}Flight;

/* Function Prototypes */
void input_flights(int n, Flight flights[n]);
int search_flights(int n, Flight flights[n], char destination[], int result[]);
void display(int count, int result[], Flight flights[]);

int main()
{
   int n=4, count;
   char search_dest[50];
   Flight flights[n];
   int result[n];
    
    input_flights(  n,   flights);
    printf("\nEnter destination to search: ");
    scanf("%s", search_dest);
    count = search_flights(  n,   flights,   search_dest,   result);
    display(  count,   result,   flights);

    return 0;
}

/* Function to input flight details */
void input_flights(int n, Flight flights[n])
{
    for(int i=0; i<n; i++){
        printf("\nEnter details of flight %d\n", i+1);

        printf("Enter flight number: ");
        scanf("%d", &flights[i].flightnumber);
        // write code

        printf("Enter destination: ");
        scanf("%s", flights[i].destination);
        // write code

        printf("Enter available seats: ");
        scanf("%d", &flights[i].seats);
        // write code
        printf("\n");
    }
}

/* Function to search flights */
int search_flights(int n, Flight flights[n], char search_dest[], int result[])
{
    int count=0;
    for(int i=0; i<n; i++){
        if(strcmp(flights[i].destination, search_dest)==0){
            result[count] = i;
            count++;
        }
    }
        // write condition using strcmp
        // store index in result[count]
        return count;
}

/* Function to display result */
void display(int count, int result[], Flight flights[])
{
   if(count==0)
        printf("No flight available to the given destination\n");
   else{
        printf("Flights available:\n");
        for(int i=0; i<count; i++)
        printf("Flight Number: %d\n", flights[result[i]].flightnumber);
   }
}