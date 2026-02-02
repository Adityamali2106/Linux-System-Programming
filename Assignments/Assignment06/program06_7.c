//////////////////////////////////////////////////////////////////////////////////
//
//      Program Name : program06_7.c
//      Description  : This program dynamically loads a shared library at runtime
//                     using dlopen,retrieves functions with dlsym,executes them,
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
    void (*fp)(int, char *);
    void (*fp2)();
    int iChoice = 0;
    int iValue = 0;
    char Arr[30] = {'\0'};

    handel = dlopen("./programSevenServer.so", RTLD_LAZY);
    if (NULL == handel)
    {
        printf("%s", dlerror());
        return -1;
    }

    while (1)
    {
        printf("---------------------------------------------------------------------------\n");
        printf("-------------------------- 1. SetValues       -----------------------------\n");
        printf("-------------------------- 2. GetValues       -----------------------------\n");
        printf("-------------------------- 3. ResetValues     -----------------------------\n");
        printf("-------------------------- 4. Exit            -----------------------------\n");
        printf("---------------------------------------------------------------------------\n");

        printf("\n                        Enter your Choice :                              \n");
        printf("                          ");
        scanf("%d", &iChoice);

        if (iChoice == 1)
        {
            printf("                          Enter New value to reset (numbers and name) : \t");
            scanf("%d%s", &iValue, Arr);

            fp = dlsym(handel, "SetValues");
            if (fp == NULL)
            {
                printf("%s", dlerror());
                return -1;
            }

            fp(iValue, Arr);
        }
        else if (iChoice == 2)
        {
            fp2 = dlsym(handel, "GetValue");
            if (fp == NULL)
            {
                printf("%s", dlerror());
                return -1;
            }

            fp2();
        }
        else if (iChoice == 3)
        {
            printf("                          Enter New value to reset (numbers and name) : \t");
            scanf("%d%s", &iValue, Arr);
            fp = dlsym(handel, "ResetValues");
            if (fp == NULL)
            {
                printf("%s", dlerror());
                return -1;
            }

            fp(iValue, Arr);
        }
        else if (iChoice == 4)
        {
            printf("                          thank you...!\n");
            break;
        }
        else if (iChoice > 0 || iChoice < 4)
        {
            printf("Enter valid choice \n");
        }
    }

    dlclose(handel);

    return 0;
}