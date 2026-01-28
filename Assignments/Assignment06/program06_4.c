//////////////////////////////////////////////////////////////////////////////////
//
//      Program Name : program06_2.c
//      Description  : This program • A valid shared library is loaded
//                     • An invalid or missing function name is passed to dlsym()
//                     program gracefully handle errors using dlerror() and print messag on screen.
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

    handel = dlopen("./programTwoServe", RTLD_LAZY);
    //////////////////////////////////////////////////////////////////////////////////
    //
    //  dlopen();
    //          It loads the dynamic shared object(.so file) to access the
    //          functionality of that shared object
    //
    //////////////////////////////////////////////////////////////////////////////////

    if (NULL == handel)
    {
        printf("%s\n", dlerror());
        //////////////////////////////////////////////////////////////////////////////////
        //
        //  dlerror();
        //              it is used to get the messege if any function call failes in dlopen API
        //
        //////////////////////////////////////////////////////////////////////////////////

        return -1;
    }

    fp = dlsym(handel, "Additin");

    if (NULL == fp)
    {
        printf("%s\n", dlerror());
        return -1;
    }

    iRet = fp(11, 10);

    printf("Addition is : %d\n", iRet);

    fp = dlsym(handel, "Substraction");
    //////////////////////////////////////////////////////////////////////////////////
    //
    //  dlsym();
    //          It is used to obtain the memory address of a symbol(function or variable)
    //          from a dynamically loaded shared object(library) at runtime
    //
    //////////////////////////////////////////////////////////////////////////////////

    if (NULL == fp)
    {
        printf("%s\n", dlerror());
        return -1;
    }

    iRet = fp(11, 10);

    printf("Substraction is : %d\n", iRet);

    iRet = dlclose(handel + 5);
    //////////////////////////////////////////////////////////////////////////////////
    //
    //  dlclose();
    //             dlclose function is used to deallocate the access of a shared object
    //             from the process stack
    //
    //////////////////////////////////////////////////////////////////////////////////

    if (iRet != 0)
    {
        printf("%s\n", dlerror());
        return -1;
    }

    return 0;
} // End of main
