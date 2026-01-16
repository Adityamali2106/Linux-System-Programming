#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int TotalFiles = 0;
int TotalDir = 0;
long long TotalSize = 0;
char LargeFileName[1024];
long LargeFileSize = 0;

void ScanDir(const char *path)
{
    DIR *dir = NULL;
    struct stat sobj;
    struct dirent *ptr = NULL;
    char fullPath[1024];

    dir = opendir(path);
    if (dir == NULL)
    {
        return;
    }

    TotalDir++;

    while (ptr = readdir(dir))
    {
        if (strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0)
        {
            continue;
        }

        snprintf(fullPath, sizeof(fullPath), "%s/%s", path, ptr->d_name);

        if (lstat(fullPath, &sobj) == -1)
            continue;

        if (S_ISREG(sobj.st_mode))
        {
            TotalFiles++;
            TotalSize = TotalSize + sobj.st_size;
            if (LargeFileSize < sobj.st_size)
            {
                strcpy(LargeFileName, ptr->d_name);
                LargeFileSize = sobj.st_size;
            }
        }
        else if (S_ISDIR(sobj.st_mode))
        {
            ScanDir(fullPath);
        }
    }
    closedir(dir);
}

int main()
{
    char Name[100] = {'\0'};
    printf("Enter the path for Directory : \t");
    scanf("%[^'\n']s", Name);

    ScanDir(Name);

    printf("Files       : %d \n", TotalFiles);
    printf("Dirs        : %d \n", TotalDir);
    printf("Total Size  : %lld\n", TotalSize);
    printf("Largest     : %s (%ld) \n", LargeFileName, LargeFileSize);

    return 0;
}