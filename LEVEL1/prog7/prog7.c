#include <stdio.h> //program Compare two strings using user-defined functions

// Function prototypes
void readString(char *str);
void removeNewline(char *str);
int compareStrings(char *str1, char *str2); // to be implemented
void displayResult(int result);

int main() {
    char str1[100], str2[100];

    // Input
    printf("Enter first string: ");
    readString(str1);
    printf("Enter second string: ");
    readString(str2);;

    // Pre-processing
    removeNewline(str1);
    removeNewline(str2);

    // Processing
    int result = compareStrings(str1, str2);
    // Output
    displayResult(result);
    return 0;
}

// Reads input
void readString(char *str) {
    fgets(str, 100, stdin);

}

// Removes newline
void removeNewline(char *str) {
    int i=0; 
    while (str[i] != '\0'){
        if(str[i]=='\n'){
            str[i] = '\0';
            break;
        }
        i++;
    }

}


int compareStrings(char *str1, char *str2) {
    // Write your logic here
    int i=0, j=0;
    
    while(str1[i] != '\0' && str2[i] != '\0'){
        if(str1[i] > str2[i]){
            return 1;
        }
        else if(str2[i] > str1[i]){
            return -1;
        }
        i++;
    }
    
    if(str1[i] == '\0' && str2[i] == '\0'){
        return 0;
    }
    else if(str1[i] != '\0'){
        return 1;
    }
    else{
        return -1;
    }
    
}

// Displays result
void displayResult(int result) {
    if(result == 0)
        printf("Both strings are equal.\n");
    else if(result == 1)
        printf("First string is lexicographically greater.\n");
    else
        printf("Second string is lexicographically greater.\n");
   
}