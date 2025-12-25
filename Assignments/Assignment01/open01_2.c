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
//  Function Name : OpenFile
//  Description :   It is used to open the file in given mode
//  Input :         Charactor pointer, Charactor pointer
//  Output :        Integer (Which return fd)
//  Author :        Aditya Vijay Mali
//  Date :          20/12/2025
//
//////////////////////////////////////////////////////////////////////////////////////

int OpenFile(char *Ptr, char *Mode)
{
    int fd = 0;
    if (Mode[0] == 'R' && Mode[1] == 'W')
    {
        printf("In Rw\n");
        fd = open(Ptr, O_RDWR | O_CREAT, 0777);
    }
    else if (Mode[0] == 'W')
    {
        printf("In W\n");
        fd = open(Ptr, O_WRONLY | O_CREAT, 0777);
    }
    else if (Mode[0] == 'R')
    {
        printf("In R\n");
        fd = open(Ptr, O_RDONLY | O_CREAT, 0777);
    }
    else if (Mode[0] == 'A')
    {
        printf("In A\n");
        fd = open(Ptr, O_APPEND | O_CREAT, 0777);
    }
    else
    {
        printf("File cannot be open the mode is Invalid \n");
    }
    return fd;
}

//////////////////////////////////////////////////////////////////////////////////////
//
//	Entery point Function for the application
//
//////////////////////////////////////////////////////////////////////////////////////

int main()
{
    char Arr[30];
    char Mode[5];
    int iRet = 0;

    memset(Arr, '\0', sizeof(Arr));

    printf("Enter file name : \n");
    scanf("%[^'\n']s", Arr);

    printf("Give mode in which you want to open file(R,W,RW,A) : \n");
    scanf(" %[^'\n']s", Mode);

    iRet = OpenFile(Arr, Mode);

    if (iRet == -1)
    {
        printf("File open failed  because : %s\n", strerror(errno));
        return -1;
    }
    else if (iRet == 0)
    {
        return 0;
    }
    else
    {
        printf("File gets opened succesfully with fd : %d \n", iRet);
    }

    close(iRet);

    return 0;
}
