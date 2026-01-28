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

    //////////////////////////////////////////////////////////////////////////////////
    //
    //  Call for dlopen("path",RTLD_LAZY)
    //
    //////////////////////////////////////////////////////////////////////////////////

    handel = dlopen("./programFiveServer.so", RTLD_LAZY);

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

    iRet = dlclose(handel);

    if (iRet != 0)
    {
        printf("%s", dlerror());
        return -1;
    }

    //////////////////////////////////////////////////////////////////////////////////
    //
    //  Call for dlopen("path",RTLD_NOW)
    //
    //////////////////////////////////////////////////////////////////////////////////

    handel = dlopen("./programFiveServer.so", RTLD_NOW);

    fp = dlsym(handel, "Addition");

    iRet = fp(30, 25);

    printf("Addition is : %d\n", iRet);

    fp = dlsym(handel, "Substraction");

    iRet = fp(30, 25);

    printf("Substraction is : %d\n", iRet);

    iRet = dlclose(handel);

    if (iRet != 0)
    {
        printf("%s", dlerror());
        return -1;
    }

    return 0;
} // End of main

/////////////////////////////////////////////////////////////////////////////////////////////
//
//  what i observed after using RTLD_LEZY and RTLD_NOW:
//
//          The dlopen() part of the code dynamically loads the shared library so at runtime,
//          first using RTLD_LAZY to delay symbol resolution until the functions are actually
//          used, and then using RTLD_NOW to resolve all symbols immediately during library
//          loading, allowing the program to demonstrate the difference in when symbol
//          - related errors are detected.
//
//////////////////////////////////////////////////////////////////////////////////////////////
