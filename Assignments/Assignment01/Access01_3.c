//////////////////////////////////////////////////////////////////////////////////////
//
//  Required hider files
//
//////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

//////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : myStrcmp
//  Description :   It is used to Compare two strings
//  Input :         Charactor pointer, Charactor pointer
//  Output :        Integer
//  Author :        Aditya Vijay Mali
//  Date :          20/12/2025
//
//////////////////////////////////////////////////////////////////////////////////////

int myStrcmp(const char *string1, const char *string2)
{
    int iCnt;

    for (iCnt = 0; string1[iCnt] != '\0' || string2[iCnt] != '\0'; iCnt++)
    {
        if (string1[iCnt] != string2[iCnt])
        {
            return 1;
        }
    }

    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////
//
//	Entery point Function for the application
//
//////////////////////////////////////////////////////////////////////////////////////

int main()
{
    char Arr[30];
    char Mode[10];
    int iRet = 0;

    char read[] = "read";
    char write[] = "write";
    char exe[] = "execute";

    memset(Arr, '\0', sizeof(Arr));
    memset(Mode, '\0', sizeof(Mode));

    printf("Enter file name : \n");
    scanf("%[^'\n']s", Arr);

    printf("Give mode in which you want to open file(read/write/execute) : \n");
    scanf(" %[^'\n']s", Mode);

    printf("%s \n", Mode);

    if ((myStrcmp(Mode, read) == 0))
    {
        printf("In Read\n");
        iRet = access(Arr, R_OK);
    }
    else if ((myStrcmp(Mode, write)) == 0)
    {
        printf("In W\n");
        iRet = access(Arr, W_OK);
    }
    else if ((myStrcmp(Mode, exe)) == 0)
    {
        printf("In exe\n");
        iRet = access(Arr, X_OK);
    }
    else
    {
        printf("Invalid Mode\n");
    }

    if (iRet == 0)
    {
        printf("Accessible\n");
    }
    else
    {
        printf("Not Accessible because : %s \n", strerror(errno));
        return -1;
    }

    return 0;
}
