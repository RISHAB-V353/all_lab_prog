//Replace All Vowels in Both Strings with * and Compare

#include <stdio.h>
#include <string.h>

void replaceVowels(char str[])
{
    int i;

    for(i=0;str[i]!='\0';i++)
    {
        char ch=str[i];

        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||
           ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
        {
            str[i]='*';
        }
    }
}

int main()
{
    char s1[100],s2[100];

    printf("Enter first string: ");
    scanf(" %[^\n]",s1);

    printf("Enter second string: ");
    scanf(" %[^\n]",s2);

    replaceVowels(s1);
    replaceVowels(s2);

    printf("\nModified String 1: %s",s1);
    printf("\nModified String 2: %s\n",s2);

    if(strcmp(s1,s2)==0)
        printf("Strings are equal.");
    else
        printf("Strings are different.");

    return 0;
}