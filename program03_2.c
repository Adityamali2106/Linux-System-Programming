#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

int MyStrCmp(const char *string1, const char *string2)
{
    int iCounter;

    for (iCounter = 0; string1[iCounter] != '\0' || string2[iCounter] != '\0'; iCounter++)
    {

        if (string1[iCounter] != string2[iCounter])
        {
            return 1;
        }
    }

    return 0;
}

void CheckFile(char *dirName, char *fileName)
{
    DIR *dir = NULL;
    struct dirent *ptr = NULL;
    char path[100];
    int flag = 0;

    memset(path, '\0', sizeof(path));

    dir = opendir(dirName);

    while (ptr = readdir(dir))
    {
        if (MyStrCmp(ptr->d_name, fileName) == 0)
        {
            realpath(ptr->d_name, path);
            printf("File found %s \n", path);
            flag = 1;
        }
    }

    if (flag == 0)
    {
        printf("file %s not found in directory %s \n", fileName, dirName);
    }
}

int main()
{
    char dir[50];
    char file[50];

    printf("Enter Directory name : \n");
    scanf("%[^'\n']s", dir);

    printf("Enter file name which you want to find : \n");
    scanf(" %[^'\n']s", file);

    CheckFile(dir, file);

    return 0;
}