#include <stdio.h>

typedef struct {
    int id;
    char name[50];
    float marks;
} Student;

// Function declarations
void inputStudents(Student students[], int n);
void writeToTextFile(Student students[], int n, const char *filename);
int readFromTextFile(Student newstudents[], const char *filename);
void printStudents(Student students[], int n);

int main() {
    int n;

    printf("Enter the size:");
    scanf("%d", &n);
    printf("\n");

    if(n<1){
        printf("Invalid input");
        return 0;
    }

    // declare arrays here
    Student students[n], newstudents[n];

    // call input function
    inputStudents(students, n);

    // call write function
    writeToTextFile(students, n, "students.txt");

    // call read function
    int count = readFromTextFile(newstudents, "students.txt");
    printf("\n--- Students read from ASCII file ---\n");

    // call print function
    printStudents(newstudents, count);

    return 0;
}

void inputStudents(Student students[], int n) {
    for(int i=0; i<n; i++){
        printf("Enter details for student %d:\n", i+1);
        printf("Enter ID: ");
        scanf("%d", &students[i].id);
        printf("Enter name: ");
        scanf("%s", students[i].name);
        printf("Enter Marks: \n");
        scanf("%f", &students[i].marks);
    }
}

void writeToTextFile(Student students[], int n, const char *filename) {

    FILE *fp = fopen(filename, "w");
    for(int i=0; i<n; i++){
        fprintf(fp, "%d %s %f\n", students[i].id,
                                students[i].name,
                                students[i].marks);
    }
    
    fclose(fp);
}

int readFromTextFile(Student newstudents[], const char *filename) {

    FILE *fp = fopen(filename, "r");
    int i=0;
    while(fscanf(fp, "%d %s %f", &newstudents[i].id,
                                 newstudents[i].name,
                                 &newstudents[i].marks)==3){
                                    i++;
                                 }
    fclose(fp);

    return i;

}

void printStudents(Student students[], int n) {

    for(int i=0; i<n; i++){
        printf("%d %s %.2f",students[i].id, students[i].name, students[i].marks);
        printf("\n");
    }

}