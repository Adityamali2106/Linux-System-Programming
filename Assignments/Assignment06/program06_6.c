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
    void *handle;
    void (*fp)();

    handle = dlopen("programSixServer.so", RTLD_LAZY);
    if (handle == NULL)
    {
        printf("%s\n", dlerror());
        return -1;
    }

    fp = dlsym(handle, "hello");
    if (fp == NULL)
    {
        printf("%s\n", dlerror());
        return -1;
    }

    dlclose(handle);

    return 0;
}

//////////////////////////////////////////////////////////////////////////////////
//
//      Without using export LD_LIBRARY_PATH. the output is :
//              programSixServer.so: cannot open shared object file: No such file or directory
//      Using export LD_LIBRARY_PATH. the output is :
//              Jay Ganesh... From Library
//      Explination
//              This shows how Linux finds shared libraries at runtime. If a
//              shared library is kept in a custom folder and the program is
//              run without LD_LIBRARY_PATH, Linux cannot find the library and
//              the program fails. When LD_LIBRARY_PATH is set to include that
//              folder, Linux knows where to look, successfully loads the library,
//              and the program runs correctly.
//
//////////////////////////////////////////////////////////////////////////////////
