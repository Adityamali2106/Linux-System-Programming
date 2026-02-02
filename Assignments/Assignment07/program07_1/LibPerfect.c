#include <dlfcn.h>
#include <stdio.h>

int IsPerfect(int No)
{
    void *handel = NULL;
    int (*fp)(int);
    int iRet = 0;

    handel = dlopen("./LibHelper.so", RTLD_LAZY);
    if (NULL == handel)
    {
        return -1;
    }

    fp = dlsym(handel, "SumOfFactors");
    if (NULL == fp)
    {
        return -1;
    }

    iRet = fp(No);

    if (iRet == No)
    {
        return 0;
    }
    else
    {
        return -1;
    }

    dlclose(handel);
}