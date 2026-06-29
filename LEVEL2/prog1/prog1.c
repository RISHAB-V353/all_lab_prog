#include <stdio.h>
#include<string.h>

/* Function Declarations */
void readString(char str[]);
int findPattern(char str[], char pat[], int start);
int replacePattern(char str[], char pat[], char rep[], char result[]);
void displayResult(int found, char result[]);

int main() {
    char str[100], rep[100], pat[100], result[200];
    printf("Enter the string: ");
    readString(str);
    printf("Enter the pattern: ");
    readString(pat);
    printf("Enter the replacement: ");
    readString(rep);
    int found = replacePattern(str, pat, rep, result);
    displayResult(found, result);
    return 0;
}

/* Function to read string */
void readString(char str[]) {
    fgets(str, 100, stdin);
    int i=0; 
    while(str[i] !='\0'){
        if(str[i] == '\n'){
            str[i] = '\0';
            break;
        }
        i++;
    }
}

/* Function to check pattern match */
int findPattern(char str[], char pat[], int start) {
    int i=0;
    while(pat[i] != '\0'){
        if(str[start+i] != pat[i]){
            return 0;
        }
        i++;
    }
    return 1;
}

/* Function to replace pattern */
int replacePattern(char str[], char pat[], char rep[], char result[]) {
    int i=0, j=0, found=0, patlen = strlen(pat);
    while(str[i] != '\0'){
        if(findPattern(str, pat, i)){
            int k=0;
            while(rep[k] != '\0'){
                result[j++] = rep[k++];
            }
            i += patlen;
            found = 1;
        }
        else{
            result[j++] = str[i++];
        }
    }
    result[j] = '\0';
    return found;
}

/* Function to display result */
void displayResult(int found, char result[]) {
    if (found == 0) 
        printf("Pattern does not exist");
    else{
        printf("The main string after replacement is:\n");
        printf("%s", result);
    }
}