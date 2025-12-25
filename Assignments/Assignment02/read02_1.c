#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>

void ReadFile(char *ptr)
{
    int fd = 0;
    char Buffer[100];
    int iRet = 0;
    struct stat sobj;

    fd = open(ptr, O_RDONLY);

    if (fd == -1)
    {
        printf("File can not opened because : %s \n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    fstat(fd, &sobj);

    memset(Buffer, '\0', sizeof(Buffer));
    iRet = read(fd, Buffer, sobj.st_size);

    printf("Data From File : %s\n", Buffer);

    printf("Total bytes read from file : %d\n", iRet);

    close(fd);
}

int main()
{
    char fileNane[50];

    printf("Enter file name : \n");
    scanf("%[^'\n']s", fileNane);

    ReadFile(fileNane);

    return 0;
}