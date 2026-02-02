#include <string.h>
#include <stdio.h>

int iValue = 0;
char str[30] = {'\0'};

void SetValues(int no, char *name)
{
    iValue = no;
    strcpy(str, name);
}

void GetValue()
{
    printf("Value is : %d\n Youre name is : %s \n", iValue, str);
}

void ResetValues(int no, char *name)
{
    iValue = no;
    strcpy(str, name);
}
