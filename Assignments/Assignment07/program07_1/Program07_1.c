//////////////////////////////////////////////////////////////////////////////////
//
//      Program Name : program06_1.c
//      Description  : This program dynamically loads a shared library at runtime
//                     using dlopen,retrieves arithmetic functions with dlsym,
//                     executes them, and safely unloads the library using dlclose.
//      Author       : Aditya Vijay Mali
//      Date         : 28/01/2026
//
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
//
//  Required Hider Files
//
//////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////////////////
//
//  Entry Point function for the application
//
//////////////////////////////////////////////////////////////////////////////////

int main()
{
    void *handel = NULL;
    int (*fp)(int);
    int iRet = 0, iValue = 0;

    printf("Enter a number to check it is perfect number :\n");
    scanf("%d", &iValue);

    handel = dlopen("./LibPerfect.so", RTLD_LAZY);
    if (NULL == handel)
    {
        printf("%s\n", dlerror());
        return -1;
    }

    fp = dlsym(handel, "IsPerfect");

    iRet = fp(iValue);

    if (iRet == 0)
    {
        printf("%d is a Perfect Number\n", iValue);
    }
    else
    {
        printf("%d is Not a Perfect Number\n", iValue);
    }

    return 0;
}