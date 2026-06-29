#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    char name[100], lang[50];
    int year;
    float rating;
}Movie;

int count_movie(char input[]);
Movie* allocateMem(int count);
void readmovies(char filename[], int count, Movie *movies);
void displaymovies(Movie *movies, int n);
void sortmovies(Movie *movies, int count);
void writemovies(Movie *movies, int count, char filename[]);
void freeMem(Movie **movies);

int main(){
    char input[] = "IMDb_400_Movies1.csv";
    char output[] = "sorted_movies.csv";

    int count = count_movie(input);
    Movie *movies = allocateMem(count);
    readmovies(input, count, movies);

    int n;
    printf("Enter number of movies to display: ");
    scanf("%d", &n);
    if(n>count){
        n=count;
    }

    displaymovies(movies, n);
    sortmovies(movies, count);
    printf("\n");
    displaymovies(movies, n);
    writemovies(movies, count, output);
    freeMem(&movies);

    return 0;
}

int count_movie(char input[]){
    FILE *fp = fopen(input, "r");

    if(fp == NULL){
        printf("Errro opening file!");
        exit(0);
    }
    char line[100];
    int i=-1;

    while(fgets(line, sizeof(line), fp)){
        i++;
    }

    fclose(fp);
    return i;
}

Movie* allocateMem(int count){
    Movie *movies = (Movie*)malloc(sizeof(Movie)*count);

    if(movies == NULL){
        printf("Memory allocation failed!");
        exit(0);
    }
    return movies;
}

void readmovies(char filename[], int count, Movie *movies){
    FILE *fp = fopen(filename, "r");
    
    if(fp == NULL){
        printf("Error opening file!");
        exit(0);
    }

    char line[300];
    fgets(line, sizeof(line), fp);

    for(int i=0; i<count; i++){
        if(fgets(line, sizeof(line), fp)){
            sscanf(line, "%99[^,],%49[^,],%d,%f", movies[i].name,
                                              movies[i].lang,
                                              &movies[i].year,
                                              &movies[i].rating);
        }
    }

    fclose(fp);

}

void displaymovies(Movie *movies, int n){
    for(int i=0; i<n; i++){
        printf("%s %s %d %f\n", movies[i].name,
        movies[i].lang, movies[i].year, movies[i].rating);
    }
}

void sortmovies(Movie *movies, int count){
    Movie temp;
    for(int i=0; i<count-1; i++){
        for (int j = 0; j < count-i-1; j++){
            if(strcmp(movies[j].name, movies[j+1].name)>0){
                temp = movies[j];
                movies[j] = movies[j+1];
                movies[j+1] = temp;
            }
        }
    }
}

void writemovies(Movie *movies, int count, char filename[]){
    FILE *fp = fopen(filename, "w");
    if(fp == NULL){
        printf("Error Creating csv file");
        exit(0);
    }
    fprintf(fp, "Movie Name,Language,Year,Rating\n");

    for(int i=0; i<count; i++){
        fprintf(fp, "%s,%s,%d,%f\n", movies[i].name, movies[i].lang, movies[i].year, movies[i].rating);
    }

    fclose(fp);
}

void freeMem(Movie **movies){
    free(*movies);
    *movies = NULL;
}