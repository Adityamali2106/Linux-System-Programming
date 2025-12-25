#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

void ReadFile(char *ptr, int iNo)
{
    int fd = 0;
    char Buffer[100];

    fd = open(ptr, O_RDONLY);

    if (fd == -1)
    {
        printf("File can not opened because : %s \n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    memset(Buffer, '\0', sizeof(Buffer));
    read(fd, Buffer, iNo);

    printf("Data From File : %s\n", Buffer);

    close(fd);
}

int main()
{
    char fileNane[50];
    int iValue = 0;

    printf("Enter file name : \n");
    scanf("%[^'\n']s", fileNane);

    printf("Enter number of bytes to read from file : \n");
    scanf("%d", &iValue);

    ReadFile(fileNane, iValue);

    return 0;
}