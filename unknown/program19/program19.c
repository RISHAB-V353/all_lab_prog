//Remove All Occurrences of a Character

#include <stdio.h>

int main()
{
    char str[100], ch;
    int i, j = 0;
    char result[100];

    printf("Enter a string: ");
    scanf(" %[^\n]", str);

    printf("Enter character to remove: ");
    scanf(" %c", &ch);

    for(i = 0; str[i] != '\0'; i++)
    {
        if(str[i] != ch)
        {
            result[j++] = str[i];
        }
    }

    result[j] = '\0';

    printf("Modified String: %s", result);

    return 0;
}