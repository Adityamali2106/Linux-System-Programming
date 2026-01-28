//////////////////////////////////////////////////////////////////////////////////
//
//      Program Name : program06_2.c
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
    int (*fp)(int, int);
    int iRet = 0;

    handel = dlopen("./programOneServer.so", RTLD_LAZY);

    if (NULL == handel)
    {
        printf("%s", dlerror());
        return -1;
    }

    fp = dlsym(handel, "Addition");

    iRet = fp(11, 10);

    printf("Addition is : %d\n", iRet);

    fp = dlsym(handel, "Substraction");

    iRet = fp(11, 10);

    printf("Substraction is : %d\n", iRet);

    dlclose(handel);

    return 0;
} // End of main
