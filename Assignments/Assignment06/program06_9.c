//////////////////////////////////////////////////////////////////////////////////
//
//      Program Name : program06_9.c
//      Description  : This program dynamically loads a shared library at runtime
//                     using dlopen,retrieves functions with dlsym stores the
//                     address of function is function Pointer Array and display
//                     its address and its result ,executes them, and safely unloads
//                     the library using dlclose.
//      Author       : Aditya Vijay Mali
//      Date         : 02/02/2026
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
    int (*fp[5])(int, int);
    int iCnt = 0;

    handel = dlopen("./programNineServer.so", RTLD_LAZY);

    if (NULL == handel)
    {
        printf("%s\n", dlerror());
        return -1;
    }

    fp[0] = dlsym(handel, "Addition");
    fp[1] = dlsym(handel, "Substraction");
    fp[2] = dlsym(handel, "Multiplication");
    fp[3] = dlsym(handel, "Division");
    fp[4] = dlsym(handel, "Mod");

    for (iCnt = 0; iCnt < 5; iCnt++)
    {
        printf("Function Address is %p\n", fp[iCnt]);
        printf("Return Value of Function %d\n", fp[iCnt](11, 10));
    }

    dlclose(handel);

    return 0;
}