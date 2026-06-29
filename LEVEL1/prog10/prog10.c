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

int main() {
    int n;

    printf("Enter number of students: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input\n");
        return 0;
    }

    Student students[n], newstudents[n];

    // Input
    printf("\nEnter student details (ID Name Marks):\n");
    inputStudents(students, n);

    // Write to binary file
    writeToBinaryFile(students, n, "students.dat");

    // Read from binary file
    int count = readFromBinaryFile(newstudents, "students.dat", n);

    // Display data
    printf("\n--- Students read from Binary File ---\n");
    printStudents(newstudents, count);

    return 0;
}

// Input student details
void inputStudents(Student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d\n", i + 1);

        printf("Enter ID: ");
        scanf("%d", &students[i].id);

        printf("Enter Name: ");
        scanf("%49s", students[i].name);

        printf("Enter Marks: ");
        scanf("%f", &students[i].marks);
    }
}

// Write to binary file
void writeToBinaryFile(Student students[], int n, const char *filename) {
    FILE *fp = fopen(filename, "wb");

    if (fp == NULL) {
        printf("Error opening file for writing\n");
        return;
    }

    fwrite(students, sizeof(Student), n, fp);

    fclose(fp);

    printf("\nData written to %s successfully.\n", filename);
}

// Read from binary file
int readFromBinaryFile(Student students[], const char *filename, int n) {
    FILE *fp = fopen(filename, "rb");

    if (fp == NULL) {
        printf("Error opening file for reading\n");
        return 0;
    }

    int count = fread(students, sizeof(Student), n, fp);

    fclose(fp);

    return count;
}

// Display students
void printStudents(Student students[], int count) {
    if (count == 0) {
        printf("No records found.\n");
        return;
    }

    printf("\nID\tName\tMarks\n");
    printf("----------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%.2f\n",
               students[i].id,
               students[i].name,
               students[i].marks);
    }
}