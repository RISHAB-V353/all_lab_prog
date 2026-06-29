//String Compression

#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int i, count;

    printf("Enter a string: ");
    scanf("%s", str);

    printf("Compressed String: ");

    for(i = 0; str[i] != '\0';)
    {
        count = 1;

        while(str[i] == str[i + 1])
        {
            count++;
            i++;
        }

        printf("%c%d", str[i], count);
        i++;
    }

    return 0;
}