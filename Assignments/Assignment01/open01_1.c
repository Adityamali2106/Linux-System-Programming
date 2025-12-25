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
//  Description :   It is used to open the file if present then open
//                  if not then create and open the file
//  Input :         Charactor pointer, Charactor pointer
//  Output :        Integer (Which return fd)
//  Author :        Aditya Vijay Mali
//  Date :          20/12/2025
//
//////////////////////////////////////////////////////////////////////////////////////

int OpenFile(char *Ptr)
{
    int fd = 0;
    fd = open(Ptr, O_CREAT | O_TRUNC, 0777);

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
    int iRet = 0;

    memset(Arr, '\0', sizeof(Arr));

    printf("Enter file name : \n");
    scanf("%[^'\n']s", Arr);

    iRet = OpenFile(Arr);

    if (iRet == -1)
    {
        printf("File open failed  because : %s\n", strerror(errno));
        return -1;
    }
    else
    {
        printf("File gets opened succesfully with fd : %d \n", iRet);
    }

    close(iRet);
    return 0;
}