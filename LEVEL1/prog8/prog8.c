#include <stdio.h>  //program 8 

// Function Prototypes
void input(char *str);
void concatenate_strings(char *str1, char *str2);
void display(char *str);

int main() {

    char str1[100], str2[100];

    printf("Enter the first string:\n");
    input(str1);

    printf("Enter the second string:\n");
    input(str2);

    // Concatenate strings
    concatenate_strings(str1, str2);

    // Display result
    display(str1);

    return 0;
}

// Function to read string
void input(char *str) {

    scanf("%s", str);
}

// Function to concatenate strings
void concatenate_strings(char *str1, char *str2) {

    int i = 0, j = 0;

    // Move to end of first string
    while(str1[i] != '\0') {

        i++;
    }

    // Copy second string to first string
    while(str2[j] != '\0') {

        str1[i] = str2[j];

        i++;
        j++;
    }

    // Add null character
    str1[i] = '\0';
}

// Function to display string
void display(char *str) {

    printf("Concatenated Result:%s\n", str);
}