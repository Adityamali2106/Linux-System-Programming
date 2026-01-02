#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h>

void print_permissions(mode_t mode)
{
    printf("Permissions: ");
    printf((S_ISDIR(mode)) ? "d" : "-");
    printf((mode & S_IRUSR) ? "r" : "-");
    printf((mode & S_IWUSR) ? "w" : "-");
    printf((mode & S_IXUSR) ? "x" : "-");
    printf((mode & S_IRGRP) ? "r" : "-");
    printf((mode & S_IWGRP) ? "w" : "-");
    printf((mode & S_IXGRP) ? "x" : "-");
    printf((mode & S_IROTH) ? "r" : "-");
    printf((mode & S_IWOTH) ? "w" : "-");
    printf((mode & S_IXOTH) ? "x" : "-");
    printf("\n");
}

int main()
{
    struct dirent *ptr = NULL;
    struct stat sobj;
    DIR *dp = NULL;
    char Path[500];
    char Buffer[1024];

    memset(Path, '\0', sizeof(Path));
    memset(Buffer, '\0', sizeof(Buffer));

    printf("Enter Directory Path : \n");
    scanf("%[^'\n']s", Path);

    dp = opendir(Path);

    if (dp == NULL)
    {
        printf("%s \n", strerror(errno));
        return -1;
    }

    while (ptr = readdir(dp))
    {
        if (strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0)
            continue;

        lstat(ptr->d_name, &sobj);

        printf("Name of File : %s\n", ptr->d_name);

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

        printf("Size of a file : %ld\n", sobj.st_size);

        printf("Permissions of file are : ");
        print_permissions(sobj.st_mode);

        printf("Last File Modification: %s \n", ctime(&sobj.st_mtime));

        snprintf(Buffer, sizeof(Buffer), "%s/%s", Path, ptr->d_name);
    }

    return 0;
}