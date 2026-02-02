//////////////////////////////////////////////////////////////////////////////////
//
//      Program Name : program07_2.c
//      Description  : This program dynamically loads a shared library at runtime
//                     using dlopen,get string from user and pass it to shared objects function
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
    int (*fp)(char *);
    char str[80];
    int iRet = 0;

    printf("Enter a string :\n");
    scanf("%[^'\n']s", str);

    handel = dlopen("./LibMystrlen.so", RTLD_LAZY);

    if (NULL == handel)
    {
        printf("%s\n", dlerror());
        return -1;
    }

    fp = dlsym(handel, "Mystrlen");

    iRet = fp(str);

    printf("LEngth of the string is : %d \n", iRet);

    return 0;
}