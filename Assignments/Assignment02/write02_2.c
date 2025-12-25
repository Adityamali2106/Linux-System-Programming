#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>

int MyStrlen(char *str)
{
    int iCnt = 0;
    for (iCnt = 1; str[iCnt] != '\0'; iCnt++)
    {
    }

    return iCnt;
}

void WriteToFile(char *ptr, char *Buffer)
{
    int fd = 0;
    int iRet = 0, iSize = 0;

    fd = open(ptr, O_CREAT | O_WRONLY | O_APPEND, 0777);

    if (fd == -1)
    {
        printf("File can not opened because : %s \n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    iSize = MyStrlen(Buffer);

    iRet = write(fd, Buffer, iSize);

    printf("Total bytes printed into file are : %d\n", iRet);

    close(fd);
}

int main()
{
    char fileNane[50];
    char Buffer[100];

    memset(Buffer, '\0', sizeof(Buffer));

    printf("Enter file name : \n");
    scanf("%[^'\n']s", fileNane);

    printf("Enter Data to write into file : \n");
    scanf(" %[^'\n']s", Buffer);

    WriteToFile(fileNane, Buffer);

    return 0;
}