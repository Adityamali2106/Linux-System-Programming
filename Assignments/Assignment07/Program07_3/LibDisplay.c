/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    Program Name     : LibDisplay
//    Description      : This is a libarary file the display function display the string on console and the length of a string
//    Author           : Aditya Vijay Mali
//    Date             : 02/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////

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
