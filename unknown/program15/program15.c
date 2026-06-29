//Replace Characters

#include <stdio.h>

int main()
{
    char str[100];
    char oldChar, newChar;
    int i;

    printf("Enter a string: ");
    scanf(" %[^\n]", str);

    printf("Enter character to replace: ");
    scanf(" %c", &oldChar);

    printf("Enter new character: ");
    scanf(" %c", &newChar);

    for(i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == oldChar)
            str[i] = newChar;
    }

    printf("Modified String: %s", str);

    return 0;
}