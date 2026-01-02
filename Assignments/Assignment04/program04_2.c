#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

int CopyFiles(char *source, char *dest, off_t offset)
{
    int fd1 = 0, fd2 = 0;
    int iRet = 0, iRet2 = 0;
    char Buffer[100];
    struct stat sb;

    memset(Buffer, '\0', sizeof(Buffer));

    fd1 = open(source, O_RDONLY);

    if (fd1 == -1)
    {
        printf("Source File cant open because : %s \n", strerror(errno));
        return -1;
    }

    fd2 = open(dest, O_WRONLY | O_CREAT, 0777);

    if (fd2 == -1)
    {
        printf("Dest File cant open because : %s \n", strerror(errno));
        return -1;
    }

    if (stat(source, &sb) == 0)
    {
        chmod(dest, sb.st_mode);
    }

    while ((iRet = read(fd1, Buffer, sizeof(Buffer))) > 0)
    {
        iRet2 = pwrite(fd2, Buffer, iRet, offset);
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
    if (argc != 3)
    {
        printf("Usage: %s <destination_dir> <source_dir> <source_dir> ....\n", argv[0]);
        return 1;
    }

    char *source_file = argv[1];
    char *dest_file = argv[2];
    int Offset = 0;
    int iRet = 0;

    printf("Enter the Offset : ");
    scanf("%d", &Offset);

    iRet = CopyFiles(source_file, dest_file, Offset);

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