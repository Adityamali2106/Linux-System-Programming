#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

void OpenDir(char const *DirName)
{
    DIR *dp = NULL;
    struct dirent *ptr = NULL;
    struct stat sobj;

    dp = opendir(DirName);

    if (dp == NULL)
    {
        printf("%s \n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    while (ptr = readdir(dp))
    {
        lstat(ptr->d_name, &sobj);

        printf("Name of File : %s\n", ptr->d_name);
        printf("Size of a file : %ld\n", sobj.st_size);

        printf("Type of a file is : \t");

        if (S_ISBLK(sobj.st_mode))
        {
            printf("Block Divice\n");
        }
        else if (S_ISCHR(sobj.st_mode))
        {
            printf("Character Device \n");
        }
        else if (S_ISDIR(sobj.st_mode))
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
        else if (S_ISFIFO(sobj.st_mode))
        {
            printf("Pip e file \n");
        }
        else if (S_ISLNK(sobj.st_mode))
        {
            printf("Sicial file\n");
        }
        else
        {
            printf("Unknown\n");
        }

        printf("\n\n");
    }
}

int main()
{
    char dirName[50];

    printf("Enter Directory name : \n");
    scanf("%[^'\n']s", dirName);

    OpenDir(dirName);

    return 0;
}