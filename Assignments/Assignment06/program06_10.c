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

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <Library_Path><SymbolName>\n", argv[0]);
        return -1;
    }

    void *handel = NULL;
    void (*fp)(int, int);

    handel = dlopen(argv[1], RTLD_LAZY);
    if (NULL == handel)
    {
        printf("Can not open the shared object because \n%s\n", dlerror());
        return -1;
    }

    fp = dlsym(handel, argv[2]);
    if (NULL == fp)
    {
        printf("%s\n", dlerror());
        return -1;
    }

    printf("Function Address is : %p\n", fp);

    return 0;
}
