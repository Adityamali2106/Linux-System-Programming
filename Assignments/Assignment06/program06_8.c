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
    int (*fp)(char *);
    int iChoice = 0;
    char Arr[100] = {'\0'};
    int iRet = 0;

    while (1)
    {
        printf("---------------------------------------------------------------------------------\n");
        printf("-------------------------- 1. Count Lowercase letters   --------------------------\n");
        printf("-------------------------- 2. Count Uppercase Letters   --------------------------\n");
        printf("-------------------------- 3. Count Digits              --------------------------\n");
        printf("-------------------------- 4. Exit                      --------------------------\n");
        printf("---------------------------------------------------------------------------\n");

        printf("\n                         Enter your Choice :                              \n");
        printf("                           ");
        scanf("%d", &iChoice);

        if (iChoice == 1)
        {
            printf("                       Enter String              : \t");
            scanf(" %s", Arr);

            handel = dlopen("./programEightServer.so", RTLD_LAZY);
            if (NULL == handel)
            {
                printf("%s", dlerror());
                return -1;
            }

            fp = dlsym(handel, "CountCapital");

            iRet = fp(Arr);

            printf("                        Total count of capital Letters are : %d\n", iRet);

            dlclose(handel);
        }
        else if (iChoice == 2)
        {
            printf("                       Enter String              : \t");
            scanf(" %s", Arr);

            handel = dlopen("./programEightServer.so", RTLD_LAZY);
            if (NULL == handel)
            {
                printf("%s", dlerror());
                return -1;
            }

            fp = dlsym(handel, "CountSmall");

            iRet = fp(Arr);

            printf("                        Total count of Small Letters are : %d\n", iRet);

            dlclose(handel);
        }
        else if (iChoice == 3)
        {
            printf("                       Enter String              : \t");
            scanf(" %s", Arr);

            handel = dlopen("./programEightServer.so", RTLD_LAZY);
            if (NULL == handel)
            {
                printf("%s", dlerror());
                return -1;
            }

            fp = dlsym(handel, "CountDigits");

            iRet = fp(Arr);

            printf("                        Total count of Digits in a string is : %d\n", iRet);

            dlclose(handel);
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

    return 0;
}