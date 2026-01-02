#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

int CopyFiles(char *dest, char *source)
{
    int fd1 = 0, fd2 = 0;
    int iRet = 0, iRet2 = 0;
    char Buffer[100];
    struct stat sb;

    printf("In Copy Files %s\t %s \n", dest, source);

    memset(Buffer, '\0', sizeof(Buffer));

    fd1 = open(dest, O_WRONLY | O_CREAT | O_APPEND, 0777);

    if (fd1 == -1)
    {
        printf("Dest File cant open because : %s \n", strerror(errno));
        return -1;
    }

    fd2 = open(source, O_RDONLY);

    if (fd2 == -1)
    {
        printf("Source File cant open because : %s \n", strerror(errno));
        return -1;
    }

    if (stat(source, &sb) == 0)
    {
        chmod(dest, sb.st_mode);
    }

    while ((iRet = read(fd2, Buffer, sizeof(Buffer))) > 0)
    {
        iRet2 = write(fd1, Buffer, iRet);
        if (iRet2 == 0)
        {
            close(fd1);
            close(fd2);
            printf("%s\n", strerror(errno));
            return -1;
        }
    }

    close(fd1);
    close(fd2);
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc == 0)
    {
        printf("Usage: %s <destination_dir> <source_dir> <source_dir> ....\n", argv[0]);
        return 1;
    }

    char *source_file = argv[1];
    int iCnt = 0;
    int iRet = 0;

    for (iCnt = 2; argv[iCnt] != NULL; iCnt++)
    {
        iRet = CopyFiles(source_file, argv[iCnt]);
    }

    if (iRet < 0)
    {
        printf("Files can not copied \n");
    }
    else
    {
        printf("File copied successfully!\n");
    }

    return 0;
}