//////////////////////////////////////////////////////////////////////////////////
//
//      Program Name : program07_2.c
//      Description  : This program dynamically loads a shared library at runtime
//                     using dlopen,get two numbers from user and perform addition
//                     and subtraction by importing two differnt so files and display it on scereen,
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
    int (*fp)(int, int);
    int iRet = 0, iValue1 = 0, iValue2 = 0;

    printf("Enter two numbers : \n");
    scanf("%d%d", &iValue1, &iValue2);

    handel = dlopen("./LibAddition.so", RTLD_LAZY);
    if (NULL == handel)
    {
        printf("%s\n", dlerror());
        return -1;
    }

    fp = dlsym(handel, "Addition");

    iRet = fp(iValue1, iValue2);

    printf("Addition is : %d\n", iRet);

    dlclose(handel);
    handel = NULL;

    handel = dlopen("./LibSubstraction.so", RTLD_LAZY);
    if (NULL == handel)
    {
        printf("%s", dlerror());
        return -1;
    }

    fp = dlsym(handel, "Substraction");

    iRet = fp(iValue1, iValue2);

    printf("Substraction is : %d\n", iRet);

    dlclose(handel);
    handel = NULL;

    return 0;
}