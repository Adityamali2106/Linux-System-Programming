#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

int CopyFiles(char *source, char *dest)
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

    fd2 = open(dest, O_WRONLY | O_CREAT | O_TRUNC);

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
        iRet2 = write(fd2, Buffer, iRet);
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

int main()
{
    char source_file[50];
    char dest_file[50];
    char LargName[50];
    int iRet = 0;

    memset(LargName, '\0', sizeof(LargName));

    printf("Enter Source File name : \n");
    scanf("%[^'\n']s", source_file);

    printf("Enter Dest File name : \n");
    scanf(" %[^'\n']s", dest_file);

    iRet = CopyFiles(source_file, dest_file);

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