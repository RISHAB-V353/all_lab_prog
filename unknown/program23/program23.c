//Strings with Dynamic Memory Allocation

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *str;

    str = (char *)malloc(100 * sizeof(char));

    if(str == NULL)
    {
        printf("Memory Allocation Failed");
        return 0;
    }

    printf("Enter a string: ");
    scanf(" %[^\n]", str);

    printf("Entered String: %s", str);

    free(str);

    return 0;
}