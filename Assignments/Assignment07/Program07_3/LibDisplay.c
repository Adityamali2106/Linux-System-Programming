#include <stdio.h>

void Display(char *str)
{
    int i = 0;
    printf("Entered string is : %s \n", str);

    for (i = 0; str[i] != '\0'; i++)
    {
    }

    printf("Length of the string is : %d\n", i);
}