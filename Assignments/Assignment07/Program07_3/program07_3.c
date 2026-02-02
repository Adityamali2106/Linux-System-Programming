//////////////////////////////////////////////////////////////////////////////////
//
//      Program Name : program07_3.c
//      Description  : This program dynamically loads a shared library at runtime
//                     using dlopen,get String from user and Display it by importing so files
//                     and safely unloads the library using dlclose.
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
    void (*fp)(char *);
    char str[80];

    printf("Enter a string :\n");
    scanf("%[^'\n']s", str);

    handel = dlopen("./LibDisplay.so", RTLD_LAZY);

    if (NULL == handel)
    {
        printf("%s\n", dlerror());
        return -1;
    }

    fp = dlsym(handel, "Display");

    fp(str);

    return 0;
}