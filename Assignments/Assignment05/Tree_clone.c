#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <string.h>

void PrintDepth(int Depth)
{
    for (int i = 0; i < Depth; i++)
    {
        printf("\t");
    }
}

void DisplayTree(char *path, int Depth)
{
    struct dirent *ptr = NULL;
    struct stat sobj;
    DIR *dir = NULL;
    char FullPath[1024];

    dir = opendir(path);
    if (dir == NULL)
    {
        return;
    }

    while (ptr = readdir(dir))
    {
        if (strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0)
        {
            continue;
        }

        snprintf(FullPath, sizeof(FullPath), "%s/%s", path, ptr->d_name);

        if (lstat(FullPath, &sobj) == -1)
        {
            continue;
        }

        PrintDepth(Depth);

        if (S_ISREG(sobj.st_mode))
        {
            printf("[R] %s\n", ptr->d_name);
        }
        else if (S_ISDIR(sobj.st_mode))
        {
            printf("[D] %s/\n", ptr->d_name);
            DisplayTree(FullPath, Depth + 1);
        }
        else if (S_ISLNK(sobj.st_mode))
        {
            printf("[L] %s\n", ptr->d_name);
        }
        else
        {
            printf("[?] %s\n", ptr->d_name);
        }
    }
    closedir(dir);
}

int main()
{
    char path[1024];
    printf("Enter the path of Diirectiry \n");
    scanf("%s", path);

    printf("%s/\n", path);
    DisplayTree(path, 1);

    return 0;
}