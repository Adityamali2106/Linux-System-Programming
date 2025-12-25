#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <dirent.h>

void OpenDir(char const *DirName)
{
    DIR *dp = NULL;
    struct dirent *ptr = NULL;

    dp = opendir(DirName);

    while (ptr = readdir(dp))
    {
        if (ptr->d_type == 4)
        {
            continue;
        }

        printf("File name : %s \n", ptr->d_name);
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