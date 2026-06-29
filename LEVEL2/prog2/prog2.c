#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[100];
    char language[50];
    int year;
    float rating;
} Movie;

/* Function Prototypes */

int countMovies(char filename[]);
Movie* allocateMemory(int count);
void readMovies(char filename[], Movie *movies, int count);
void displayMoviesFromFile(int n, Movie *movies);
void sortMovies(Movie *movies, int count);
void freeMemory(Movie **movies);

/* Main Function */

int main()
{
    char input[] = "IMDb_400_Movies1.csv";
    char output[] = "output.csv";
    int count = countMovies(input);
    Movie *movies = allocateMemory(count);
    readMovies(input, movies, count);
    int n;
    printf("Enter how many movie records to display: ");
    scanf("%d", &n);
    if(n > count)
    {
        n = count;
    }
    printf("\nBefore Sorting:\n\n");
    displayMoviesFromFile(n, movies);
    sortMovies(movies, count);
    printf("\nAfter Sorting:\n\n");
    displayMoviesFromFile(n, movies);
    printf("\nSorted movie data stored successfully.\n");
    freeMemory(&movies);
    return 0;
}

/* Function Definitions */

int countMovies(char filename[])
{
   FILE *fp = fopen(filename, "r");
  
    if(fp == NULL)
    {
        printf("File cannot be opened\n");
        exit(0);
    }
    char line[300];
    int i=-1;
    while(fgets(line, sizeof(line), fp)){
        i++;
    }
    fclose(fp);
    return i;
}

Movie* allocateMemory(int count)
{
    Movie *movies = (Movie*)malloc(count*sizeof(Movie));
    if(movies == NULL)
    {
        printf("Memory allocation failed\n");
        exit(0);
    }
    return movies;
}

void readMovies(char filename[], Movie *movies, int count)
{
    FILE *fp = fopen(filename, "r");
    if(fp == NULL)
    {
        printf("File cannot be opened\n");
        exit(0);
    }
    
    char line[300];
    fgets(line, sizeof(line), fp);
    
    int i=0;
    while(fgets(line, sizeof(line), fp)){
        sscanf(line, "%99[^,], %49[^,], %d, %f", movies[i].name, movies[i].language, &movies[i].year, &movies[i].rating);
        i++;
    }
    fclose(fp);
}

void displayMoviesFromFile(int n, Movie *movies)
{
    
    for(int i=0; i<n; i++)
    {
        printf("%s | %s | %d | %.1f\n", movies[i].name, movies[i].language, movies[i].year, movies[i].rating );
    }
    
}

void sortMovies(Movie *movies, int count)
{
    Movie temp;
    for(int i=0; i<count-1; i++){
        for(int j=0; j<count-i-1; j++){
            if(strcmp(movies[j].name, movies[j+1].name)>0){
                temp = movies[j];
                movies[j] = movies[j+1];
                movies[j+1] = temp;
            }
        }
    }
}

void freeMemory(Movie **movies)
{
    free(*movies);
    *movies = NULL;
}