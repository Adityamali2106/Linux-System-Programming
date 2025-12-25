#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/types.h>
#include <dirent.h>

int StrCmper(char *str1, char *str2)
{
    int iCount1 = 0, iCount2 = 0;

    while (str1[iCount1] != '\0')
    {
        iCount1++;
    }

    while (str2[iCount2] != '\0')
    {
        iCount2++;
    }

    if (iCount1 > iCount2)
    {
        return iCount1;
    }
    else
    {
        return iCount2;
    }
}

void OpenDir(char const *DirName, char *LargestName)
{
    DIR *dp = NULL;
    struct dirent *ptr = NULL;
    int iRet = 0, iComp = 0;
    struct stat sobj;

    dp = opendir(DirName);

    if (dp == NULL)
    {
        printf("Directory Can not opened : %s ", strerror(errno));
        exit(EXIT_FAILURE);
    }

    while (ptr = readdir(dp))
    {
        if (ptr->d_type == 4)
        {
            continue;
        }

        iRet = StrCmper(ptr->d_name, LargestName);
        if (iRet > iComp)
        {
            iComp = iRet;
            LargestName = ptr->d_name;
        }
        else
        {
            continue;
        }
    }
    printf("Largest file in the Directory is : %s \n", LargestName);
    lstat(LargestName, &sobj);
    printf("Size of %s is %ld\n", LargestName, sobj.st_size);
}

int main()
{
    char dirName[50];
    char LargName[50];

    memset(LargName, '\0', sizeof(LargName));

    printf("Enter Directory name : \n");
    scanf("%[^'\n']s", dirName);

    OpenDir(dirName, LargName);

    return 0;
}