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
    int iValue1 = 0, iValue2 = 0;
    int iRet = 0, iChoice = 0;

    while (1)
    {
        printf("---------------------------------------------------------------------------\n");
        printf("-------------------------- 1. Addition        -----------------------------\n");
        printf("-------------------------- 2. Substraction    -----------------------------\n");
        printf("-------------------------- 3. Multiplication  -----------------------------\n");
        printf("-------------------------- 4. Division        -----------------------------\n");
        printf("-------------------------- 5. Exit            -----------------------------\n");
        printf("---------------------------------------------------------------------------\n");

        printf("\n                        Enter your Choice :                              \n");
        printf("                          ");
        scanf("%d", &iChoice);
        if (iChoice == 1)
        {
            printf("                          Enter two numbers for addition : \t");
            scanf("%d%d", &iValue1, &iValue2);

            handel = dlopen("./programThreeServer.so", RTLD_LAZY);

            if (NULL == handel)
            {
                printf("%s", dlerror());
                return -1;
            }

            fp = dlsym(handel, "Addition");

            iRet = fp(iValue1, iValue2);

            printf("                          Addition is : %d\n", iRet);

            dlclose(handel);
        }
        else if (iChoice == 2)
        {
            printf("                          Enter two numbers for substarction : \t");
            scanf("%d%d", &iValue1, &iValue2);

            handel = dlopen("./programOneServer.so", RTLD_LAZY);

            if (NULL == handel)
            {
                printf("%s", dlerror());
                return -1;
            }

            fp = dlsym(handel, "Substraction");

            iRet = fp(iValue1, iValue2);
            printf("                          Substraction is : %d\n", iRet);
            dlclose(handel);
        }
        else if (iChoice == 3)
        {
            printf("                          Enter two numbers for Multiplication : \t");
            scanf("%d%d", &iValue1, &iValue2);

            handel = dlopen("./programThreeServer.so", RTLD_LAZY);

            if (NULL == handel)
            {
                printf("%s", dlerror());
                return -1;
            }

            fp = dlsym(handel, "Multiplication");

            iRet = fp(iValue1, iValue2);

            printf("                          Multiplication is : %d\n", iRet);

            dlclose(handel);
        }
        else if (iChoice == 4)
        {
            printf("                          Enter two numbers for addition : \t");
            scanf("%d%d", &iValue1, &iValue2);

            if (iValue2 == 0)
            {
                printf("                          Cannot Devide by Zero\n");
                printf("                          Plese enter valid number\n");
                continue;
            }

            handel = dlopen("./programThreeServer.so", RTLD_LAZY);

            if (NULL == handel)
            {
                printf("%s", dlerror());
                return -1;
            }

            fp = dlsym(handel, "Division");

            iRet = fp(iValue1, iValue2);

            printf("                          Division is : %d\n", iRet);

            dlclose(handel);
        }
        else if (iChoice == 5)
        {
            printf("                          Thankyou for wisting \n");
            printf("                          Exiting the apllication \n");
            break;
        }
        else
        {
            printf("                          Invalid choice Please Enter Valid Choice \n");
            continue;
        }
    }

    return 0;
} // End of main
