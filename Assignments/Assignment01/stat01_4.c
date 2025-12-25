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
#include <sys/stat.h>
#include <time.h>

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

void DispalyStat(char *Arr)
{
    int fd = 0;
    int iRet = 0;
    struct stat sobj;

    fd = OpenFile(Arr);

    if (fd == -1)
    {
        printf("File open failed  because : %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    iRet = fstat(fd, &sobj);

    printf("Size of a file %ld\n", sobj.st_size);

    printf("Inode number : %ld\n", sobj.st_ino);

    printf("Permissions : %d\n", sobj.st_mode);

    printf("HardLinks : %ld\n", sobj.st_nlink);

    printf("Owner uid/gid : %d \n", sobj.st_gid);

    printf("File type : \t");
    if (S_ISDIR(sobj.st_mode))
    {
        printf("Directory File \n");
    }
    else if (S_ISREG(sobj.st_mode))
    {
        printf("Reguler file\n");
    }
    else if (S_ISSOCK(sobj.st_mode))
    {
        printf("Socket file\n");
    }
    else if (S_ISLNK(sobj.st_mode))
    {
        printf("Sicial file\n");
    }

    printf("Last file access : %s\n", ctime(&sobj.st_atime));

    printf("Last file modification : %s\n", ctime(&sobj.st_mtime));

    close(iRet);
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

    DispalyStat(Arr);
    return 0;
}