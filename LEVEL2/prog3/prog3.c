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
void getSearchMovieName(char searchName[]);
void removeNewLine(char str[]);
int linearSearch(Movie *movies, int count, char searchName[]);
void displayMovie(Movie *movies, int position);
void freeMemory(Movie **movies);

/* Main Function */

int main()
{
    char searchName[200];
    int count = countMovies("sorted_movies.csv");
    Movie *movies = allocateMemory(count);
    readMovies("sorted_movies.csv", movies, count);
    getSearchMovieName(searchName);
    removeNewLine(searchName);
    int position = linearSearch(movies, count, searchName);
    displayMovie(movies, position);
    freeMemory(&movies);
    return 0;
}

/* Function Definitions */

int countMovies(char filename[])
{
    FILE *fp = fopen(filename, "r");
    if(fp == NULL){
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
    if(movies == NULL){
        printf("Memory allocation failed\n");
    }
    return movies;
}

void readMovies(char filename[], Movie *movies, int count)
{
    FILE *fp = fopen(filename, "r");
    if(fp == NULL){
        printf("File cannot be opened\n");
        exit(0);
    }
    char line[300];
    fgets(line, sizeof(line), fp);
    int i=0;
    while(fgets(line, sizeof(line), fp)){
        sscanf(line, "%99[^,],%49[^,],%d,%f", movies[i].name, movies[i].language, &movies[i].year, &movies[i].rating);
        i++;
    }
    fclose(fp);
}

void getSearchMovieName(char searchName[])
{
    printf("Enter movie name to search: ");
    fgets(searchName, 200, stdin);

}

void removeNewLine(char str[])
{
    int i=0;
    while(str[i] != '\0'){
        if(str[i] == '\n'){
            str[i] = '\0';
        }
        i++;
    }
}

int linearSearch(Movie *movies, int count, char searchName[])
{
    for(int i=0; i<count; i++){
      if(strcmp(movies[i].name, searchName)==0){
          return i;
      }  
    }
    return -1;
}

void displayMovie(Movie *movies, int position)
{
    if(position == -1){
        printf("\nMovie not found\n");
    }
    else{
        printf("\nMovie found at index %d in array and row %d in the file\n\n", position, position+2);
        printf("Movie Name : %s\n", movies[position].name);
        printf("Language   : %s\n", movies[position].language);
        printf("Year       : %d\n", movies[position].year);
        printf("Rating     : %.1f\n", movies[position].rating);
    }

}

void freeMemory(Movie **movies)
{
    free(*movies);
    *movies = NULL;
}