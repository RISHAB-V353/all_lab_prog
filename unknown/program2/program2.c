//String Comparison and Matching Using User-Defined Functions

#include <stdio.h>
#include <string.h>

void readString(char str[])
{
    fgets(str,100,stdin);
    str[strcspn(str,"\n")]='\0';
}

int compareStrings(char s1[],char s2[])
{
    return strcmp(s1,s2);
}

int main()
{
    char str1[100],str2[100];

    printf("Enter first string: ");
    readString(str1);

    printf("Enter second string: ");
    readString(str2);

    if(compareStrings(str1,str2)==0)
        printf("Strings are equal.");
    else
        printf("Strings are different.");

    return 0;
}