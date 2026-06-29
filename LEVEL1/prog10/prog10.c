#include <stdio.h>

typedef struct {
    int id;
    char name[50];
    float marks;
} Student;

// Function declarations
void inputStudents(Student students[], int n);
void writeToBinaryFile(Student students[], int n, const char *filename);
int readFromBinaryFile(Student students[], const char *filename, int n);
void printStudents(Student students[], int count);

// Main
int main() {
    int n;
    printf("Enter the size:\n");
    scanf("%d", &n);

    if(n<1){
        printf("Invalid input\n");
        return 0;
    }
    
    Student students[n], newstudents[n];

    // 1. Input
    inputStudents(students, n);
    
    // 2. Write to binary file
    writeToBinaryFile(students, n, "students.dat");

    // 3. Read from binary file
    int count = readFromBinaryFile(newstudents, "students.dat", n);
   
    // 7. Print read data
    printf("\n--- Students read from Binary file ---\n");
    printStudents(newstudents, count);

    return 0;
}

// Read input
void inputStudents(Student students[], int n) {
    for(int i=0; i<n; i++){
        scanf("%d", &students[i].id);
         scanf("%s", students[i].name);
         scanf("%f", &students[i].marks);
    }
}

// Write to binary file
void writeToBinaryFile(Student students[], int n, const char *filename) {

    FILE *fp = fopen(filename, "wb");

    fwrite(students, sizeof(Student), n, fp);

    fclose(fp);
    
}

// Read from binary file
int readFromBinaryFile(Student newstudents[], const char *filename, int n) {
    FILE *fp = fopen(filename, "rb");

    int count = fread(newstudents, sizeof(Student), n, fp);
    fclose(fp);

    return count;
}

// Print students
void printStudents(Student students[], int n) {
    for(int i=0; i<n; i++){
        printf("%d %s %.2f\n", students[i].id, students[i].name, students[i].marks);
    }
}
